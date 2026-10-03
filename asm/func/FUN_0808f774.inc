	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0808F7BC @ =0x000034E4
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xc0
	bl MainSprite_AdvanceAnim
	ldr r0, _0808F7C0 @ =0x00003504
	adds r2, r4, r0
	ldrh r3, [r2]
	movs r0, #0
	ldrsh r1, [r2, r0]
	movs r0, #0x58
	rsbs r0, r0, #0
	cmp r1, r0
	ble _0808F79A
	subs r0, r3, #5
	strh r0, [r2]
_0808F79A:
	ldr r0, _0808F7C4 @ =0x000009EC
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x95
	bls _0808F7B4
	ldr r1, _0808F7C8 @ =FUN_0809ae0c
	adds r0, r4, #0
	bl FUN_0808a33c
_0808F7B4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808F7BC: .4byte 0x000034E4
_0808F7C0: .4byte 0x00003504
_0808F7C4: .4byte 0x000009EC
_0808F7C8: .4byte FUN_0809ae0c
