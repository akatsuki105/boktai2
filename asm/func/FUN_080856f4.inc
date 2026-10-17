	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xca
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r0, [r0]
	movs r1, #0x7f
	ands r1, r0
	cmp r1, #0x5f
	bls _0808573E
	cmp r1, #0x60
	bne _08085712
	ldr r0, _08085750 @ =0x000002AA
	bl PlaySound_082406e0
_08085712:
	ldr r2, _08085754 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08085758 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _0808575C @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #1
	ands r0, r1
	movs r1, #0xb
	muls r0, r1, r0
	subs r0, #5
	ldr r2, _08085760 @ =0x0000031E
	adds r1, r4, r2
	strh r0, [r1]
	rsbs r0, r0, #0
	adds r2, #4
	adds r1, r4, r2
	strh r0, [r1]
_0808573E:
	movs r0, #0xca
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08085750: .4byte 0x000002AA
_08085754: .4byte 0x030046B8
_08085758: .4byte 0x000003FF
_0808575C: .4byte 0x0203B400
_08085760: .4byte 0x0000031E
