	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	movs r6, #0
	ldr r0, _080E7138 @ =0x03002B98
	ldrh r0, [r0]
	cmp r6, r0
	bgt _080E70E4
	mov r8, r0
	ldr r0, _080E713C @ =0x03002BE0
	mov ip, r0
_080E7090:
	mov r0, ip
	ldr r2, [r0]
	cmp r2, #0
	beq _080E70DA
	ldrh r1, [r7, #8]
	ldrh r0, [r2, #0x2c]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _080E7140 @ =0xFFFF0000
	adds r0, r3, #0
	ands r0, r4
	adds r4, r0, #0
	orrs r4, r1
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _080E70B6
	rsbs r0, r0, #0
_080E70B6:
	cmp r0, #0xff
	bgt _080E70DA
	ldrh r1, [r7, #0xc]
	ldrh r0, [r2, #0x30]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r3, #0
	ands r0, r5
	adds r5, r0, #0
	orrs r5, r1
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _080E70D6
	rsbs r0, r0, #0
_080E70D6:
	cmp r0, #0xff
	ble _080E7132
_080E70DA:
	movs r0, #4
	add ip, r0
	adds r6, #1
	cmp r6, r8
	ble _080E7090
_080E70E4:
	movs r0, #4
	bl FUN_080f8cf0
	cmp r0, #0
	beq _080E7144
	ldr r2, [r0]
	ldrh r1, [r7, #8]
	ldrh r0, [r2, #8]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _080E7140 @ =0xFFFF0000
	adds r0, r3, #0
	ands r0, r4
	adds r4, r0, #0
	orrs r4, r1
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _080E710E
	rsbs r0, r0, #0
_080E710E:
	cmp r0, #0xff
	bgt _080E7144
	ldrh r1, [r7, #0xc]
	ldrh r0, [r2, #0xc]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r3, #0
	ands r0, r5
	adds r5, r0, #0
	orrs r5, r1
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _080E712E
	rsbs r0, r0, #0
_080E712E:
	cmp r0, #0xff
	bgt _080E7144
_080E7132:
	movs r0, #1
	b _080E7146
	.align 2, 0
_080E7138: .4byte 0x03002B98
_080E713C: .4byte 0x03002BE0
_080E7140: .4byte 0xFFFF0000
_080E7144:
	movs r0, #0
_080E7146:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
