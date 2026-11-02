	push {lr}
	mov ip, r0
	mov r3, ip
	adds r3, #0xdc
	mov r2, ip
	adds r2, #0x80
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r3]
	str r1, [r3, #4]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r3]
	str r1, [r3, #4]
	mov r1, ip
	ldrb r0, [r1, #2]
	lsrs r0, r0, #5
	cmp r0, #7
	bhi _081E98E4
	lsls r0, r0, #2
	ldr r1, _081E97FC @ =_081E9800
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081E97FC: .4byte _081E9800
_081E9800: @ jump table
	.4byte _081E9820 @ case 0
	.4byte _081E983E @ case 1
	.4byte _081E985C @ case 2
	.4byte _081E987A @ case 3
	.4byte _081E9886 @ case 4
	.4byte _081E9892 @ case 5
	.4byte _081E989A @ case 6
	.4byte _081E98B8 @ case 7
_081E9820:
	ldrh r0, [r2]
	adds r0, #0x80
	strh r0, [r3]
	ldrh r0, [r2, #4]
	subs r0, #0x40
	strh r0, [r3, #4]
	ldrh r0, [r2, #2]
	subs r0, #8
	mov r1, ip
	adds r1, #0xae
	strh r0, [r1]
	ldrh r0, [r2, #2]
	adds r0, #0x10
	subs r1, #0x2c
	b _081E98E2
_081E983E:
	ldrh r0, [r2]
	adds r0, #0x80
	strh r0, [r3]
	ldrh r0, [r2, #4]
	adds r0, #0x80
	strh r0, [r3, #4]
	ldrh r0, [r2, #2]
	subs r0, #8
	mov r1, ip
	adds r1, #0xae
	strh r0, [r1]
	ldrh r0, [r2, #2]
	adds r0, #0x10
	subs r1, #0x2c
	b _081E98E2
_081E985C:
	ldrh r0, [r2]
	subs r0, #0x20
	strh r0, [r3]
	ldrh r0, [r2, #4]
	adds r0, #0x80
	strh r0, [r3, #4]
	ldrh r0, [r2, #2]
	subs r0, #8
	mov r1, ip
	adds r1, #0xae
	strh r0, [r1]
	ldrh r0, [r2, #2]
	adds r0, #0x10
	subs r1, #0x2c
	b _081E98E2
_081E987A:
	ldrh r0, [r2]
	subs r0, #0x60
	strh r0, [r3]
	ldrh r0, [r2, #4]
	adds r0, #0x20
	b _081E98C8
_081E9886:
	ldrh r0, [r2]
	subs r0, #0x80
	strh r0, [r3]
	ldrh r0, [r2, #4]
	subs r0, #0x20
	b _081E98C8
_081E9892:
	ldrh r0, [r2]
	subs r0, #0x40
	strh r0, [r3]
	b _081E98C4
_081E989A:
	ldrh r0, [r2]
	subs r0, #0x20
	strh r0, [r3]
	ldrh r0, [r2, #4]
	subs r0, #0x80
	strh r0, [r3, #4]
	ldrh r0, [r2, #2]
	adds r0, #0x10
	mov r1, ip
	adds r1, #0xae
	strh r0, [r1]
	ldrh r0, [r2, #2]
	subs r0, #8
	subs r1, #0x2c
	b _081E98E2
_081E98B8:
	ldrh r0, [r2]
	adds r0, #0x80
	strh r0, [r3]
	ldrh r0, [r2, #2]
	adds r0, #0x40
	strh r0, [r3, #2]
_081E98C4:
	ldrh r0, [r2, #4]
	subs r0, #0x60
_081E98C8:
	strh r0, [r3, #4]
	ldrh r0, [r2, #2]
	adds r0, #0x10
	mov r1, ip
	adds r1, #0xae
	strh r0, [r1]
	ldrh r0, [r2, #2]
	subs r0, #8
	subs r1, #0x2c
	strh r0, [r1]
	ldrh r0, [r2, #4]
	subs r0, #0x10
	adds r1, #2
_081E98E2:
	strh r0, [r1]
_081E98E4:
	pop {r0}
	bx r0
