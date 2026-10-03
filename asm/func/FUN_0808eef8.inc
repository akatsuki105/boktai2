	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0808EF18 @ =0x000009EC
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0xf
	bhi _0808EF1C
	adds r1, r0, #0
	movs r0, #0x10
	subs r0, r0, r1
	lsls r0, r0, #2
	movs r1, #0
	bl FUN_0808a458
	b _0808EF24
	.align 2, 0
_0808EF18: .4byte 0x000009EC
_0808EF1C:
	movs r0, #0
	movs r1, #0
	bl FUN_0808a458
_0808EF24:
	ldr r1, _0808EF50 @ =0x000034E4
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xc0
	bl MainSprite_AdvanceAnim
	ldr r0, _0808EF54 @ =0x000009EC
	adds r2, r4, r0
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _0808EF48
	adds r0, r4, #0
	bl FUN_0808f2f0
_0808EF48:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808EF50: .4byte 0x000034E4
_0808EF54: .4byte 0x000009EC
