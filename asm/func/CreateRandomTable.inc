	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r7, #0
	ldr r6, _08237458 @ =0x0203B400
	movs r0, #3
	mov r8, r0
_0823741E:
	bl Random
	adds r4, r0, #0
	bl Random
	mov r1, r8
	ands r0, r1
	asrs r4, r0
	strh r4, [r6]
	adds r6, #2
	adds r7, #1
	ldr r5, _0823745C @ =0x000003FF
	cmp r7, r5
	ble _0823741E
	ldr r4, _08237460 @ =0x030046B8
	bl Random
	ands r0, r5
	str r0, [r4]
	ldr r4, _08237464 @ =0x030046B4
	bl Random
	ands r0, r5
	str r0, [r4]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08237458: .4byte 0x0203B400
_0823745C: .4byte 0x000003FF
_08237460: .4byte 0x030046B8
_08237464: .4byte 0x030046B4
