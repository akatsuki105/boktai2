	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r1, _08089030 @ =0x000001F5
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #6
	beq _08088FD4
	adds r0, r5, #0
	movs r1, #6
	bl Coffin_SetState
_08088FD4:
	ldr r0, _08089034 @ =0x030047A4
	ldr r3, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r3, r0
	cmp r3, #0
	bne _08089076
	ldr r1, _08089038 @ =0x0000032A
	adds r0, r5, r1
	strh r3, [r0]
	movs r0, #0xfb
	lsls r0, r0, #1
	adds r6, r5, r0
	ldrh r0, [r6]
	adds r1, r0, #1
	strh r1, [r6]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bhi _08089040
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bne _08089076
	movs r1, #0x83
	lsls r1, r1, #3
	adds r2, r5, r1
	strh r3, [r2]
	ldr r0, _0808903C @ =0x00000414
	adds r4, r5, r0
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x40
	str r2, [sp]
	movs r2, #0xc8
	str r2, [sp, #4]
	movs r2, #0xfa
	str r2, [sp, #8]
	adds r2, #0x28
	str r2, [sp, #0xc]
	movs r2, #1
	movs r3, #0
	bl FUN_080da9c4
	str r0, [r4]
	b _08089076
	.align 2, 0
_08089030: .4byte 0x000001F5
_08089034: .4byte 0x030047A4
_08089038: .4byte 0x0000032A
_0808903C: .4byte 0x00000414
_08089040:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #6
	bne _0808905C
	ldr r1, _08089080 @ =0x00000414
	adds r4, r5, r1
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x40
	ldrh r2, [r1]
	movs r1, #1
	bl FUN_080d99d4
	str r0, [r4]
_0808905C:
	movs r1, #0xc8
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r1, [r0]
	subs r1, #0x1e
	strh r1, [r0]
	ldrh r0, [r6]
	cmp r0, #8
	bls _08089076
	ldr r0, _08089084 @ =0x0000040B
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_08089076:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08089080: .4byte 0x00000414
_08089084: .4byte 0x0000040B
