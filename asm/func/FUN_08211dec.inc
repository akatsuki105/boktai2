	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	mov sb, r1
	adds r4, r6, #0
	adds r4, #0x18
	movs r0, #0x74
	bl prepare_08231510
	cmp r0, #0
	beq _08211E54
	bl FUN_0823d34c
	bl FUN_08231504
	movs r5, #0
	movs r0, #1
	rsbs r0, r0, #0
	mov r8, r0
	movs r1, #0xc7
	lsls r1, r1, #2
	adds r7, r6, r1
_08211E1C:
	bl fetch_082316e4
	strh r0, [r4]
	bl fetch_082316e4
	bl fetch_082316e4
	bl fetch_082316e4
	bl fetch_082316e4
	bl fetch_082316e4
	strh r0, [r4, #2]
	bl fetch_082316e4
	strh r0, [r4, #4]
	movs r3, #0
	ldrsh r0, [r4, r3]
	cmp r0, r8
	bne _08211E4C
	subs r0, r5, #1
	str r0, [r7]
	b _08211E54
_08211E4C:
	adds r4, #0xc
	adds r5, #1
	cmp r5, #0x3f
	ble _08211E1C
_08211E54:
	adds r4, r6, #0
	adds r4, #0x18
	movs r0, #0x63
	bl prepare_08231510
	cmp r0, #0
	beq _08211E92
	bl FUN_0823d34c
	bl FUN_08231504
	movs r5, #0
	movs r7, #1
	rsbs r7, r7, #0
_08211E70:
	bl fetch_082316e4
	strh r0, [r4, #6]
	bl fetch_082316e4
	strh r0, [r4, #8]
	bl fetch_082316e4
	strh r0, [r4, #0xa]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r7
	beq _08211E92
	adds r4, #0xc
	adds r5, #1
	cmp r5, #0x3f
	ble _08211E70
_08211E92:
	ldr r1, _08211ED8 @ =0x00000322
	adds r0, r6, r1
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	movs r3, #0xc8
	lsls r3, r3, #2
	adds r0, r6, r3
	strh r1, [r0]
	movs r1, #0xc9
	lsls r1, r1, #2
	adds r0, r6, r1
	strb r2, [r0]
	mov r0, sb
	movs r1, #0
	bl FUN_0820fe50
	movs r3, #0xc6
	lsls r3, r3, #2
	adds r4, r6, r3
	str r0, [r4]
	bl FUN_0820fea8
	ldr r0, [r4]
	movs r1, #1
	bl FUN_0820fe94
	movs r0, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08211ED8: .4byte 0x00000322
