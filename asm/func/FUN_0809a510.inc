	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0809A564 @ =0x000009EE
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _0809A534
	ldr r0, _0809A568 @ =0x000002AE
	bl PlaySound_082406e0
	ldr r1, _0809A56C @ =0x00004018
	adds r0, r5, r1
	ldr r0, [r0]
	bl TextPanel_Hide
	movs r0, #0xe
	bl FUN_08099b3c
_0809A534:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x77
	bls _0809A55E
	movs r0, #8
	bl FUN_08099b3c
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0808c658
	ldr r1, _0809A570 @ =FUN_0809a324
	adds r0, r5, #0
	movs r2, #0
	bl EntityCC28_SetState
_0809A55E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809A564: .4byte 0x000009EE
_0809A568: .4byte 0x000002AE
_0809A56C: .4byte 0x00004018
_0809A570: .4byte FUN_0809a324
