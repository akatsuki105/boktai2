	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sl, r0
	mov sb, r2
	adds r6, r3, #0
	movs r0, #0
	str r0, [sp, #4]
	cmp r1, #0
	ble _080E6490
	ldr r0, _080E64A0 @ =0x0203B400
	mov r8, r0
	ldr r5, _080E64A4 @ =0x030046B8
	ldr r7, _080E64A8 @ =0x000003FF
	adds r4, r1, #0
_080E642C:
	ldr r0, [r5]
	adds r0, #1
	ands r0, r7
	str r0, [r5]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	asrs r0, r0, #4
	adds r1, r6, #0
	bl Mod
	asrs r1, r6, #1
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _080E64AC @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	ldr r0, [r5]
	adds r0, #1
	ands r0, r7
	str r0, [r5]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	asrs r0, r0, #3
	ldr r1, [sp, #0x28]
	bl Mod
	rsbs r0, r0, #0
	subs r0, #6
	lsls r0, r0, #0x10
	ldr r2, _080E64B0 @ =0x0000FFFF
	ldr r1, [sp]
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	movs r0, #0xc5
	lsls r0, r0, #2
	add r0, sl
	mov r1, sb
	ldr r2, [sp, #0x2c]
	mov r3, sp
	bl FUN_082467d0
	subs r4, #1
	cmp r4, #0
	bne _080E642C
_080E6490:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080E64A0: .4byte 0x0203B400
_080E64A4: .4byte 0x030046B8
_080E64A8: .4byte 0x000003FF
_080E64AC: .4byte 0xFFFF0000
_080E64B0: .4byte 0x0000FFFF
