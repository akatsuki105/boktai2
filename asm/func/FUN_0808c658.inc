	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r3, r1, #0
	adds r7, r2, #0
	cmp r3, #0
	bge _0808C678
	ldr r1, _0808C674 @ =0x0000258C
	adds r0, r6, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	b _0808C6A4
	.align 2, 0
_0808C674: .4byte 0x0000258C
_0808C678:
	ldr r0, _0808C6B8 @ =0x0000258C
	adds r2, r6, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _0808C6BC @ =0x00002584
	adds r4, r6, r1
	adds r5, r6, #0
	adds r5, #0x60
	adds r0, r3, #0
	bl FUN_0808c648
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #1
	bl MainSprite_SetPose
_0808C6A4:
	cmp r7, #0
	bge _0808C6C4
	ldr r1, _0808C6C0 @ =0x000025EC
	adds r0, r6, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	b _0808C6F0
	.align 2, 0
_0808C6B8: .4byte 0x0000258C
_0808C6BC: .4byte 0x00002584
_0808C6C0: .4byte 0x000025EC
_0808C6C4:
	ldr r0, _0808C6F8 @ =0x000025EC
	adds r2, r6, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _0808C6FC @ =0x000025E4
	adds r4, r6, r1
	adds r5, r6, #0
	adds r5, #0x60
	adds r0, r7, #0
	bl FUN_0808c648
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #1
	bl MainSprite_SetPose
_0808C6F0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808C6F8: .4byte 0x000025EC
_0808C6FC: .4byte 0x000025E4
