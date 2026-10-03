	push {r4, r5, lr}
	ldr r0, _0808E474 @ =0x0300013C
	ldr r5, [r0]
	cmp r5, #0
	beq _0808E4D8
	adds r0, r5, #0
	bl FUN_0808d200
	adds r0, r5, #0
	bl FUN_0808d5cc
	adds r0, r5, #0
	bl FUN_0808d4dc
	adds r0, r5, #0
	bl FUN_0808d774
	adds r0, r5, #0
	bl FUN_0808d564
	adds r0, r5, #0
	bl FUN_0808d2ac
	ldr r1, _0808E478 @ =0x000009F9
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	bl FUN_08050d94
	cmp r0, #0
	beq _0808E4A0
	bl FUN_08050de8
	cmp r0, #0
	bne _0808E480
	ldr r2, _0808E47C @ =0x00000A3C
	adds r0, r5, r2
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	b _0808E4A0
	.align 2, 0
_0808E474: .4byte 0x0300013C
_0808E478: .4byte 0x000009F9
_0808E47C: .4byte 0x00000A3C
_0808E480:
	ldr r0, _0808E4E0 @ =0x00000A3C
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _0808E4E4 @ =0x00000A34
	adds r0, r5, r1
	movs r2, #0xb0
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r2, #0x47
	movs r3, #1
	bl MainSprite_SetPose
_0808E4A0:
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r0, [r0]
	ldr r2, _0808E4E8 @ =0x0000036A
	adds r1, r0, r2
	ldrh r1, [r1]
	subs r2, #2
	adds r0, r0, r2
	movs r4, #0
	strh r1, [r0]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #3
	movs r3, #2
	bl FUN_0808a768
	movs r0, #0x86
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r1, _0808E4EC @ =0x00000A16
	adds r0, r5, r1
	strh r4, [r0]
	ldr r1, _0808E4F0 @ =FUN_0808e008
	adds r0, r5, #0
	bl FUN_0808a33c
_0808E4D8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808E4E0: .4byte 0x00000A3C
_0808E4E4: .4byte 0x00000A34
_0808E4E8: .4byte 0x0000036A
_0808E4EC: .4byte 0x00000A16
_0808E4F0: .4byte FUN_0808e008
