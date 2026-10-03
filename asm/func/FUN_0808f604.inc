	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0808F61C @ =0x000009EC
	adds r1, r5, r0
	ldrh r0, [r1]
	cmp r0, #0xf
	bhi _0808F620
	lsls r0, r0, #2
	movs r1, #0
	bl FUN_0808a458
	b _0808F628
	.align 2, 0
_0808F61C: .4byte 0x000009EC
_0808F620:
	movs r0, #0x40
	movs r1, #0
	bl FUN_0808a458
_0808F628:
	ldr r1, _0808F660 @ =0x000034E4
	adds r0, r5, r1
	adds r4, r5, #0
	adds r4, #0xc0
	adds r1, r4, #0
	bl MainSprite_AdvanceAnim
	ldr r1, _0808F664 @ =0x00003604
	adds r0, r5, r1
	adds r1, r4, #0
	bl MainSprite_AdvanceAnim
	ldr r0, _0808F668 @ =0x000009EC
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _0808F65A
	ldr r1, _0808F66C @ =FUN_0808f670
	adds r0, r5, #0
	bl FUN_0808a33c
_0808F65A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808F660: .4byte 0x000034E4
_0808F664: .4byte 0x00003604
_0808F668: .4byte 0x000009EC
_0808F66C: .4byte FUN_0808f670
