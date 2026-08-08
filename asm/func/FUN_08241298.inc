	push {r4, r5, r6, lr}
	adds r4, r1, #0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r0, _082412C0 @ =0x00001FF8
	cmp r4, r0
	ble _082412A8
	adds r4, r0, #0
_082412A8:
	movs r0, #4
	rsbs r0, r0, #0
	ands r4, r0
	adds r0, r4, #0
	bl Malloc
	adds r5, r0, #0
	cmp r5, #0
	bne _082412C4
	movs r0, #0
	b _082412EC
	.align 2, 0
_082412C0: .4byte 0x00001FF8
_082412C4:
	asrs r1, r4, #1
	cmp r1, #0
	ble _082412DA
	ldr r0, _082412F4 @ =0x0000ABCD
	adds r2, r0, #0
	adds r0, r5, #0
_082412D0:
	strh r2, [r0]
	adds r0, #2
	subs r1, #1
	cmp r1, #0
	bne _082412D0
_082412DA:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_08243988
	adds r0, r5, #0
	bl Free
	movs r0, #1
_082412EC:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_082412F4: .4byte 0x0000ABCD
