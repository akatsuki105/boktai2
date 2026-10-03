	push {r4, r5, lr}
	adds r5, r0, #0
	bl FUN_0808b4c0
	ldr r0, _0809ABAC @ =0x000009EC
	adds r4, r5, r0
	ldrh r0, [r4]
	lsls r0, r0, #2
	ldr r1, _0809ABB0 @ =0x00001084
	bl FUN_0808a458
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x10
	bls _0809ABA4
	ldr r1, _0809ABB4 @ =0x000009F8
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r1, _0809ABB8 @ =FUN_0809ac30
	adds r0, r5, #0
	bl FUN_0808a33c
_0809ABA4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809ABAC: .4byte 0x000009EC
_0809ABB0: .4byte 0x00001084
_0809ABB4: .4byte 0x000009F8
_0809ABB8: .4byte FUN_0809ac30
