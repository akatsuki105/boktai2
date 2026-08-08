	push {r4, r5, r6, lr}
	sub sp, #0xc
	mov r5, sp
	movs r6, #0
	mov r1, sp
	bl FUN_0823201c
	mov r0, sp
	ldrb r0, [r0]
	lsls r2, r0, #0x18
	ldrb r0, [r5, #1]
	lsls r0, r0, #0x10
	orrs r2, r0
	ldrb r0, [r5, #2]
	lsls r0, r0, #8
	orrs r2, r0
	ldrb r0, [r5, #3]
	orrs r2, r0
	movs r0, #0xf0
	lsls r0, r0, #0x10
	ands r0, r2
	movs r1, #0x80
	lsls r1, r1, #0x10
	cmp r0, r1
	bne _0823221C
	ldr r0, _08232218 @ =0x0300469C
	b _0823221E
	.align 2, 0
_08232218: .4byte 0x0300469C
_0823221C:
	ldr r0, _0823224C @ =0x03004694
_0823221E:
	ldr r4, [r0]
	ldr r0, _08232250 @ =0x0000FFFF
	ands r0, r2
	adds r4, r4, r0
	lsrs r0, r2, #0x18
	movs r1, #0xf0
	ands r0, r1
	cmp r0, #0x20
	bne _08232234
	ldrh r0, [r5, #6]
	adds r6, r6, r0
_08232234:
	add r3, sp, #8
	adds r0, r4, #0
	adds r1, r2, #0
	adds r2, r6, #0
	bl FUN_08231db0
	ldr r0, [sp, #8]
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0823224C: .4byte 0x03004694
_08232250: .4byte 0x0000FFFF
