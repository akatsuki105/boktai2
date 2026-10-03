	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r2, _080C0800 @ =0xFFFF0000
	adds r0, r2, #0
	ands r0, r5
	movs r1, #0x80
	orrs r0, r1
	ldr r1, _080C0804 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xe0
	lsls r1, r1, #0xe
	adds r5, r0, #0
	orrs r5, r1
	ands r6, r2
	movs r1, #0x8d
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r1, _080C0808 @ =0x0000A8E7
	bl Video_GetAuxSprite
	movs r3, #0
	movs r2, #0x80
	lsls r2, r2, #1
	mov r8, r2
_080C07A6:
	movs r0, #0x2c
	adds r4, r3, #0
	muls r4, r0, r4
	mov r1, r8
	adds r0, r4, r1
	adds r0, r7, r0
	movs r2, #0x8d
	lsls r2, r2, #2
	adds r1, r7, r2
	movs r2, #0x10
	str r3, [sp]
	bl AuxSprite_Add
	adds r0, r4, r7
	add r0, r8
	movs r1, #0
	strh r1, [r0, #0x10]
	adds r1, r7, r4
	movs r2, #0x8e
	lsls r2, r2, #1
	adds r0, r1, r2
	str r5, [r0]
	str r6, [r0, #4]
	ldr r0, _080C080C @ =0x00000107
	adds r1, r1, r0
	movs r0, #1
	strb r0, [r1]
	adds r1, r5, #0
	adds r1, #8
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _080C0800 @ =0xFFFF0000
	ands r0, r5
	adds r5, r0, #0
	orrs r5, r1
	ldr r3, [sp]
	adds r3, #1
	cmp r3, #6
	ble _080C07A6
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C0800: .4byte 0xFFFF0000
_080C0804: .4byte 0x0000FFFF
_080C0808: .4byte 0x0000A8E7
_080C080C: .4byte 0x00000107
