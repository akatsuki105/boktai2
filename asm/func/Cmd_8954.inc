	push {r4, r5, lr}
	ldr r2, _080E129C @ =0x030046A0
	ldr r0, [r2]
	ldr r1, _080E12A0 @ =0x00000948
	adds r3, r0, r1
	ldrh r4, [r3]
	movs r0, #0
	ldrsh r1, [r3, r0]
	ldr r0, _080E12A4 @ =0x0000270E
	adds r5, r2, #0
	cmp r1, r0
	bgt _080E12A8
	adds r0, r4, #1
	b _080E12AC
	.align 2, 0
_080E129C: .4byte 0x030046A0
_080E12A0: .4byte 0x00000948
_080E12A4: .4byte 0x0000270E
_080E12A8:
	ldr r1, _080E12C8 @ =0x0000270F
	adds r0, r1, #0
_080E12AC:
	strh r0, [r3]
	ldr r0, [r5]
	movs r2, #0xf8
	lsls r2, r2, #1
	adds r3, r0, r2
	ldrh r2, [r3]
	movs r0, #0
	ldrsh r1, [r3, r0]
	ldr r0, _080E12CC @ =0x0000270E
	cmp r1, r0
	bgt _080E12D0
	adds r0, r2, #1
	b _080E12D4
	.align 2, 0
_080E12C8: .4byte 0x0000270F
_080E12CC: .4byte 0x0000270E
_080E12D0:
	ldr r1, _080E12EC @ =0x0000270F
	adds r0, r1, #0
_080E12D4:
	strh r0, [r3]
	ldr r0, [r5]
	ldr r2, _080E12F0 @ =0x00000222
	adds r3, r0, r2
	ldrh r2, [r3]
	movs r0, #0
	ldrsh r1, [r3, r0]
	ldr r0, _080E12F4 @ =0x0000270E
	cmp r1, r0
	bgt _080E12F8
	adds r0, r2, #1
	b _080E12FC
	.align 2, 0
_080E12EC: .4byte 0x0000270F
_080E12F0: .4byte 0x00000222
_080E12F4: .4byte 0x0000270E
_080E12F8:
	ldr r1, _080E1318 @ =0x0000270F
	adds r0, r1, #0
_080E12FC:
	strh r0, [r3]
	ldr r0, [r5]
	movs r2, #0x8c
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080E1318 @ =0x0000270F
	cmp r1, r0
	ble _080E131C
	adds r1, r0, #0
	b _080E1322
	.align 2, 0
_080E1318: .4byte 0x0000270F
_080E131C:
	cmp r1, #0
	bge _080E1322
	movs r1, #0
_080E1322:
	ldr r0, [r5]
	movs r2, #0x8c
	lsls r2, r2, #2
	adds r0, r0, r2
	strh r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
