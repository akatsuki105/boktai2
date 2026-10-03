	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0808EE68 @ =0x000009EC
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0xf
	bhi _0808EE6C
	lsls r0, r0, #2
	movs r1, #0
	bl FUN_0808a458
	b _0808EE74
	.align 2, 0
_0808EE68: .4byte 0x000009EC
_0808EE6C:
	movs r0, #0x40
	movs r1, #0
	bl FUN_0808a458
_0808EE74:
	ldr r1, _0808EEA0 @ =0x000034E4
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xc0
	bl MainSprite_AdvanceAnim
	ldr r0, _0808EEA4 @ =0x000009EC
	adds r2, r4, r0
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _0808EE9A
	ldr r1, _0808EEA8 @ =FUN_0808eeac
	adds r0, r4, #0
	bl FUN_0808a33c
_0808EE9A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808EEA0: .4byte 0x000034E4
_0808EEA4: .4byte 0x000009EC
_0808EEA8: .4byte FUN_0808eeac
