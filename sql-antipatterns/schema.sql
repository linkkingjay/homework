CREATE TABLE Accounts (
    account_id      SERIAL PRIMARY KEY,
    account_name    VARCHAR(20),
    first_name      VARCHAR(20),
    last_name       VARCHAR(20),
    email           VARCHAR(100),
    password_hash   CHAR(64),
    portrait_image  BLOB,
    hourly_rate     NUMERIC(9, 2)
);

CREATE TABLE BugStatur (
    status          VARCHAR(20) PRIMARY KEY
);

CREATE TABLE Bugs (
    bug_id          SERIAL PRIMARY KEY,
    date_reported   DATE NOT NULL,
    summary         VARCHAR(80),
    description     VARCHAR(1000),
    resolution      VARCHAR(1000),
    reported_by     BIGINT UNSIGNED NOT NULL,
    assigned_to     BIGINT UNSIGNED,
    verified_by     BIGINT UNSIGNED,
    status          VARCHAR(20) NOT NULL DEFAULT 'NEW',
    priority        VARCHAR(20),
    hours           NUMERIC(9, 2),
    FOREIGN KEY (reported_by) REFERENCES Accounts(account_id),
    FOREIGN KEY (assigned_to) REFERENCES Accounts(account_id),
    FOREIGN KEY (verified_by) REFERENCES Accounts(account_id),
    FOREIGN KEY (status) REFERENCES BugStatus(status)
);

CREATE TABLE Comments (
    comment_id      SERIAL PRIMARY KEY,
    bug_id          BIGINT UNSIGNED NOT NULL,
    author          BIGINT UNSIGNED NOT NULL,
    comment_date    DATETIME NOT NULL,
    comment         TEXT NOT NULL,
    FOREIGN KEY (bug_id) REFERENCES Bugs(bug_id),
    FOREIGN KEY (author) REFERENCES Accounts(account_id)
);

CREATE TABLE Screenshots (
    bug_id              BIGINT UNSIGNED NOT NULL,
    image_id            BIGINT UNSIGNED NOT NULL,
    screenshot_image    BLOB,
    caption             VARCHAR(100),
    PRIMARY KEY         (bug_id, image_id),
    FOREIGN KEY REFERENCES Bugs(bug_id)
);

CREATE TABLE Tags (
    bug_id          BIGINT UNSIGNED NOT NULL,
    tag             VARCHAR(20) NOT NULL,
    PRIMARY KEY     (bug_id, tag),
    FOREIGN KEY (bug_id) REFERENCES Bugs(bug_id)
);

CREATE TABLE Products (
    product_id      SERIAL PRIMARY KEY,
    product_name    VARCHAR(50)
);

CREATE TABLE BugsProducts (
    bug_id          BIGINT UNSIGNED NOT NULL,
    product_id      BIGINT UNSIGNED NOT NULL,
    PRIMARY KEY     (bug_id, product_id),
    FOREIGN KEY (bug_id) REFERENCES Bugs(bug_id),
    FOREIGN KEY (product_id) REFERENCES Bugs(product_id)
);
