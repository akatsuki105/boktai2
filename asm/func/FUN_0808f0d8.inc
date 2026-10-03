	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0808F0F8 @ =0x000034E4
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xc0
	bl MainSprite_AdvanceAnim
	ldr r1, _0808F0FC @ =0x000009EC
	adds r0, r4, r1
	ldrh r1, [r0]
	cmp r1, #0xf
	bhi _0808F100
	adds r0, r1, #0
	lsls r0, r0, #2
	b _0808F106
	.align 2, 0
_0808F0F8: .4byte 0x000034E4
_0808F0FC: .4byte 0x000009EC
_0808F100:
	cmp r1, #0x85
	bhi _0808F10E
	movs r0, #0x40
_0808F106:
	movs r1, #0
	bl FUN_0808a458
	b _0808F11C
_0808F10E:
	ldrh r1, [r0]
	movs r0, #0x96
	subs r0, r0, r1
	lsls r0, r0, #2
	movs r1, #0
	bl FUN_0808a458
_0808F11C:
	ldr r1, _0808F13C @ =0x000009EC
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r2, r1, #1
	strh r2, [r0]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, #0x95
	bls _0808F134
	adds r0, r4, #0
	bl FUN_0808f2f0
_0808F134:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808F13C: .4byte 0x000009EC
