	push {r4, r5, lr}
	sub sp, #8
	mov ip, r0
	adds r0, #0xb2
	ldrh r0, [r0]
	subs r0, #3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls _081D343A
	movs r2, #1
	mov r1, ip
	adds r1, #0xb4
	ldrh r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _081D3420
	movs r0, #1
	b _081D3422
_081D3420:
	movs r0, #0
_081D3422:
	cmp r0, #0
	beq _081D34E0
	movs r0, #0x9c
	lsls r0, r0, #1
	add r0, ip
	bl FUN_082342a8
	movs r0, #2
	rsbs r0, r0, #0
	ldrh r1, [r4]
	ands r0, r1
	b _081D34DE
_081D343A:
	movs r2, #1
	mov r1, ip
	adds r1, #0xb4
	ldrh r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _081D344E
	movs r0, #1
	b _081D3450
_081D344E:
	movs r0, #0
_081D3450:
	cmp r0, #0
	bne _081D34E0
	ldr r0, _081D34A0 @ =0x030046A4
	ldr r3, [r0]
	cmp r3, #0
	beq _081D34E0
	mov r2, ip
	adds r2, #0xfe
	ldr r0, _081D34A4 @ =0x03002BE0
	ldr r0, [r0]
	movs r5, #0
	ldrsh r1, [r2, r5]
	movs r5, #0x2e
	ldrsh r0, [r0, r5]
	adds r5, r2, #0
	cmp r1, r0
	bne _081D34E0
	mov r0, ip
	adds r0, #0xfc
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081D349A
	cmp r1, #0
	blt _081D349A
	ldr r0, _081D34A8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D349A
	ldr r0, _081D34AC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D34B0
_081D349A:
	movs r2, #0
	b _081D34BC
	.align 2, 0
_081D34A0: .4byte 0x030046A4
_081D34A4: .4byte 0x03002BE0
_081D34A8: .4byte 0x030046A8
_081D34AC: .4byte 0x030046AC
_081D34B0:
	lsls r0, r1, #1
	adds r1, r3, #0
	adds r1, #0x24
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r2, r0, r2
_081D34BC:
	movs r0, #0x9c
	lsls r0, r0, #1
	add r0, ip
	ldrh r3, [r5]
	lsls r3, r3, #0x10
	asrs r3, r3, #0x18
	movs r1, #0xff
	str r1, [sp]
	movs r1, #4
	str r1, [sp, #4]
	adds r1, r2, #0
	movs r2, #0
	bl FUN_08234270
	movs r0, #1
	ldrh r1, [r4]
	orrs r0, r1
_081D34DE:
	strh r0, [r4]
_081D34E0:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
