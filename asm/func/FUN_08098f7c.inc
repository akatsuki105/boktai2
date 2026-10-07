	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08098FB8 @ =0x000009F8
	adds r2, r4, r0
	movs r0, #0
	strb r0, [r2]
	ldr r0, _08098FBC @ =0x030044E0
	ldrh r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08098FC0
	movs r0, #1
	strb r0, [r2]
	adds r0, r4, #0
	movs r1, #1
	movs r2, #5
	movs r3, #7
	bl EntityCC28_DrawHP
	adds r0, r4, #0
	movs r1, #1
	movs r2, #5
	movs r3, #8
	bl EntityCC28_DrawEne
	adds r0, r4, #0
	bl FUN_0808c700
	b _08098FE4
	.align 2, 0
_08098FB8: .4byte 0x000009F8
_08098FBC: .4byte 0x030044E0
_08098FC0:
	adds r0, r4, #0
	movs r1, #1
	movs r2, #5
	movs r3, #7
	bl FUN_0808a610
	adds r0, r4, #0
	movs r1, #1
	movs r2, #5
	movs r3, #8
	bl FUN_0808a768
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0808c658
_08098FE4:
	ldr r0, _08099000 @ =0x0000282C
	adds r1, r4, r0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _08099004 @ =0x0000288C
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08099000: .4byte 0x0000282C
_08099004: .4byte 0x0000288C
