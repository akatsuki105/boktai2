	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _08093750 @ =0x000009EE
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #0x10
	bls _08093724
	adds r0, r4, #0
	bl FUN_0808c1cc
_08093724:
	ldrh r0, [r5]
	movs r1, #7
	adds r2, r1, #0
	ands r2, r0
	lsrs r0, r0, #3
	subs r1, r1, r0
	cmp r2, r1
	bge _0809375C
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r2, r4, r1
	ldr r0, [r2]
	ldr r3, _08093754 @ =0x00003FA4
	adds r1, r4, r3
	ldrh r1, [r1]
	movs r3, #0xd9
	lsls r3, r3, #2
	adds r0, r0, r3
	strh r1, [r0]
	ldr r0, [r2]
	ldr r2, _08093758 @ =0x00003FA8
	b _08093776
	.align 2, 0
_08093750: .4byte 0x000009EE
_08093754: .4byte 0x00003FA4
_08093758: .4byte 0x00003FA8
_0809375C:
	movs r0, #0x9e
	lsls r0, r0, #4
	adds r2, r4, r0
	ldr r0, [r2]
	ldr r3, _080937C4 @ =0x00003FA6
	adds r1, r4, r3
	ldrh r1, [r1]
	movs r3, #0xd9
	lsls r3, r3, #2
	adds r0, r0, r3
	strh r1, [r0]
	ldr r0, [r2]
	ldr r2, _080937C8 @ =0x00003FAA
_08093776:
	adds r1, r4, r2
	ldrh r1, [r1]
	adds r3, #4
	adds r0, r0, r3
	strh r1, [r0]
	adds r0, r4, #0
	movs r1, #1
	movs r2, #5
	movs r3, #3
	bl FUN_0808a610
	adds r0, r4, #0
	movs r1, #1
	movs r2, #5
	movs r3, #4
	bl FUN_0808a768
	ldr r0, _080937CC @ =0x000009EE
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x37
	bls _080937BC
	ldr r1, _080937D0 @ =0x00003AEE
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	bl FUN_08091e64
	adds r0, r4, #0
	bl FUN_08092744
_080937BC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080937C4: .4byte 0x00003FA6
_080937C8: .4byte 0x00003FAA
_080937CC: .4byte 0x000009EE
_080937D0: .4byte 0x00003AEE
