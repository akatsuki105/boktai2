	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	mov r8, r0
	movs r0, #0
	mov sb, r0
	add r7, sp, #0x18
	ldr r5, _080859AC @ =0xFFFF0000
	ldr r1, _080859B0 @ =0x0000FFFF
	mov sl, r1
	add r4, sp, #8
	add r6, sp, #0x10
_0808598A:
	mov r2, sb
	lsls r3, r2, #5
	ldr r2, _080859B4 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #4
	cmp r0, #0
	blt _080859B8
	asrs r0, r0, #0xc
	b _080859BE
	.align 2, 0
_080859AC: .4byte 0xFFFF0000
_080859B0: .4byte 0x0000FFFF
_080859B4: .4byte gSineTable
_080859B8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080859BE:
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #8]
	ands r0, r5
	orrs r0, r1
	mov r2, sl
	ands r0, r2
	str r0, [sp, #8]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	ldr r1, _080859E8 @ =gSineTable
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #4
	cmp r0, #0
	blt _080859EC
	asrs r0, r0, #0xc
	b _080859F2
	.align 2, 0
_080859E8: .4byte gSineTable
_080859EC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080859F2:
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r4, #4]
	ands r0, r5
	orrs r0, r1
	str r0, [r4, #4]
	mov r1, r8
	adds r1, #0x48
	ldrh r0, [r4]
	lsls r0, r0, #3
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x10]
	ands r1, r5
	orrs r1, r0
	mov r0, r8
	adds r0, #0x4a
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	mov r2, sl
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x10]
	mov r0, r8
	adds r0, #0x4c
	ldrh r1, [r4, #4]
	lsls r1, r1, #3
	ldrh r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r6, #4]
	ands r0, r5
	orrs r0, r1
	str r0, [r6, #4]
	movs r0, #0
	str r0, [sp, #0x18]
	ldr r0, [r7, #4]
	ands r0, r5
	str r0, [r7, #4]
	movs r0, #3
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r6, #0
	add r1, sp, #8
	adds r2, r7, #0
	movs r3, #1
	bl FUN_080dbd08
	movs r0, #1
	add sb, r0
	mov r1, sb
	cmp r1, #7
	ble _0808598A
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
