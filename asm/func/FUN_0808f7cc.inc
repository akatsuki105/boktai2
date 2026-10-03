	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0808F7EC @ =0x000009EC
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0xf
	bhi _0808F7F0
	adds r1, r0, #0
	movs r0, #0x10
	subs r0, r0, r1
	lsls r0, r0, #2
	movs r1, #0
	bl FUN_0808a458
	b _0808F7F8
	.align 2, 0
_0808F7EC: .4byte 0x000009EC
_0808F7F0:
	movs r0, #0
	movs r1, #0
	bl FUN_0808a458
_0808F7F8:
	ldr r0, _0808F818 @ =0x000009EC
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _0808F810
	adds r0, r4, #0
	bl FUN_0808f170
_0808F810:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808F818: .4byte 0x000009EC
