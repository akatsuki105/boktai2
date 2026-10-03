	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	mov r8, r0
	ldr r3, _080AE8D4 @ =0x030047C8
	movs r0, #0
	ldrsh r1, [r3, r0]
	ldr r2, _080AE8D8 @ =0x03003540
	movs r4, #8
	ldrsh r0, [r2, r4]
	adds r6, r1, r0
	movs r0, #2
	ldrsh r1, [r3, r0]
	movs r3, #0xa
	ldrsh r0, [r2, r3]
	adds r5, r1, r0
	adds r0, r6, #0
	subs r0, #0x80
	cmp r0, #0
	blt _080AE8DC
	asrs r1, r0, #3
	b _080AE8E2
	.align 2, 0
_080AE8D4: .4byte 0x030047C8
_080AE8D8: .4byte 0x03003540
_080AE8DC:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r1, r0, #0
_080AE8E2:
	adds r7, r1, #0
	adds r0, r5, #0
	subs r0, #0x80
	cmp r0, #0
	blt _080AE8F0
	asrs r0, r0, #3
	b _080AE8F6
_080AE8F0:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_080AE8F6:
	movs r4, #2
	rsbs r4, r4, #0
	ands r4, r0
	subs r6, #0x78
	subs r5, #0x5a
	str r5, [sp]
	mov r0, r8
	adds r1, r7, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl FUN_080adfa0
	str r5, [sp]
	mov r0, r8
	adds r1, r7, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl FUN_080ae478
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
