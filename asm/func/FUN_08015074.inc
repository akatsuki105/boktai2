	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r1, #0
	movs r0, #0
	strb r0, [r4, #1]
	mov r8, r0
	adds r7, r4, #0
	adds r7, #0x2c
	adds r5, r4, #0
	adds r5, #0x42
	mov sl, r0
	movs r0, #0x40
	adds r0, r0, r4
	mov sb, r0
_08015096:
	movs r0, #0x2c
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	adds r0, #0x70
	adds r3, r4, r0
	ldrb r0, [r7]
	cmp r0, #0
	beq _08015124
	mov r6, sb
	movs r0, #0
	ldrsh r2, [r6, r0]
	adds r1, r4, #0
	adds r1, #0x32
	mov r6, sl
	adds r0, r1, r6
	ldrh r0, [r0]
	muls r0, r2, r0
	adds r6, r1, #0
	cmp r0, #0
	blt _080150C4
	asrs r2, r0, #0xc
	b _080150CA
_080150C4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080150CA:
	ldrh r0, [r3, #0x1c]
	adds r0, r0, r2
	strh r0, [r3, #0x1c]
	ldrh r0, [r5]
	ldrh r1, [r3, #0x1e]
	adds r0, r0, r1
	strh r0, [r3, #0x1e]
	movs r2, #2
	ldrsh r1, [r5, r2]
	mov r2, sl
	adds r0, r6, r2
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080150EC
	asrs r1, r0, #0xc
	b _080150F2
_080150EC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080150F2:
	ldrh r0, [r3, #0x20]
	adds r0, r0, r1
	movs r2, #0
	strh r0, [r3, #0x20]
	ldrh r0, [r5]
	subs r0, #2
	strh r0, [r5]
	adds r1, r4, #0
	adds r1, #0x26
	add r1, r8
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _0801511E
	strb r2, [r7]
	adds r0, r3, #0
	bl FUN_0822a4e0
	b _08015124
_0801511E:
	ldrb r0, [r4, #1]
	adds r0, #1
	strb r0, [r4, #1]
_08015124:
	adds r7, #1
	adds r5, #8
	movs r6, #2
	add sl, r6
	movs r0, #8
	add sb, r0
	movs r1, #1
	add r8, r1
	mov r2, r8
	cmp r2, #5
	ble _08015096
	ldrb r0, [r4, #1]
	cmp r0, #0
	bne _08015142
	strb r0, [r4]
_08015142:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
