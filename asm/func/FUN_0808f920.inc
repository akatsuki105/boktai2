	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0808F950 @ =0x000034E4
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xc0
	bl MainSprite_AdvanceAnim
	ldr r0, _0808F954 @ =0x000009EC
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x95
	bls _0808F94A
	ldr r1, _0808F958 @ =FUN_0809ae0c
	adds r0, r4, #0
	bl FUN_0808a33c
_0808F94A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808F950: .4byte 0x000034E4
_0808F954: .4byte 0x000009EC
_0808F958: .4byte FUN_0809ae0c
