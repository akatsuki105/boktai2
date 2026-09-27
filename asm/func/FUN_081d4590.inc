	push {r4, r5, lr}
	sub sp, #8
	mov ip, r0
	ldr r0, _081D45CC @ =0x03000194
	ldr r2, [r0]
	ldr r0, _081D45D0 @ =0x03002BE0
	ldr r1, [r0]
	adds r4, r0, #0
	cmp r1, #0
	beq _081D4642
	mov r0, ip
	adds r0, #0xd4
	ldr r3, _081D45D4 @ =0x000012B0
	adds r1, r2, r3
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _081D4642
	movs r2, #0x80
	lsls r2, r2, #1
	mov r1, ip
	adds r1, #0xb4
	ldrh r0, [r1]
	ands r0, r2
	adds r5, r1, #0
	cmp r0, #0
	beq _081D45D8
	movs r0, #1
	b _081D45DA
	.align 2, 0
_081D45CC: .4byte 0x03000194
_081D45D0: .4byte 0x03002BE0
_081D45D4: .4byte 0x000012B0
_081D45D8:
	movs r0, #0
_081D45DA:
	cmp r0, #0
	bne _081D463A
	ldr r1, [r4]
	mov r0, ip
	adds r0, #0x58
	ldrh r0, [r0]
	ldrh r1, [r1, #0x2c]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _081D464C @ =0xFFFF0000
	ldr r2, [sp]
	ands r2, r3
	orrs r2, r0
	str r2, [sp]
	ldr r0, [r4]
	mov r1, ip
	adds r1, #0x5a
	ldrh r1, [r1]
	ldrh r0, [r0, #0x2e]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _081D4650 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	ldr r1, [r4]
	mov r0, ip
	adds r0, #0x5c
	ldrh r0, [r0]
	ldrh r1, [r1, #0x30]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #4]
	ldr r1, [r4]
	adds r1, #0x2c
	mov r0, sp
	mov r2, ip
	bl FUN_081d43d4
	ldr r0, [r4]
	mov r1, sp
	bl FUN_0807a91c
_081D463A:
	ldr r0, _081D4654 @ =0xFFFFFEFF
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
_081D4642:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081D464C: .4byte 0xFFFF0000
_081D4650: .4byte 0x0000FFFF
_081D4654: .4byte 0xFFFFFEFF
