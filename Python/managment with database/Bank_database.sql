use director;
create table bank_credentials(
Acc_no char(10) not null primary key,
Name varchar(30) not null,
Phone long not null,
age int not null,
address varchar(200),
email varchar(50),
mpin char(4)
);

create table bank_statements(
Acc_no char(10) not null primary key,
date_time date not null default (current_timestamp),
action long not null);

create table bank_money(
Acc_no char(10) not null primary key,
ammount long constraint check (ammount>-1) not null
);



