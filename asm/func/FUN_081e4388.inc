	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r0, _081E43CC @ =0x00000BC4
	adds r0, r0, r7
	mov sb, r0
	movs r6, #0
	movs r3, #0
	ldr r0, _081E43D0 @ =0x00000E86
	adds r5, r7, r0
	ldr r1, _081E43D4 @ =0x03003584
	mov r8, r1
	adds r0, #0xe
	adds r4, r7, r0
_081E43AC:
	adds r0, r6, #0
	str r3, [sp]
	bl FUN_08243180
	ldr r3, [sp]
	cmp r0, #0
	bne _081E43D8
	movs r0, #0xb8
	lsls r0, r0, #2
	strh r0, [r5]
	mov r1, r8
	ldr r0, [r1]
	movs r1, #0xb8
	lsls r1, r1, #7
	b _081E43E2
	.align 2, 0
_081E43CC: .4byte 0x00000BC4
_081E43D0: .4byte 0x00000E86
_081E43D4: .4byte 0x03003584
_081E43D8:
	ldr r0, _081E4440 @ =0x000002DF
	strh r0, [r5]
	mov r1, r8
	ldr r0, [r1]
	ldr r1, _081E4444 @ =0x00005BE0
_081E43E2:
	adds r0, r0, r1
	str r0, [r4]
	movs r0, #0xa4
	lsls r0, r0, #2
	add r0, sb
	adds r0, r0, r3
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	adds r4, #0x60
	adds r3, #0x60
	adds r5, #0x60
	adds r6, #1
	cmp r6, #0xf
	ble _081E43AC
	movs r0, #0x30
	mov r8, r0
	ldr r0, _081E4448 @ =0x00001454
	adds r1, r7, r0
	movs r0, #0xc0
	lsls r0, r0, #3
	adds r2, r7, r0
	ldr r5, _081E444C @ =0x00000E6E
	movs r4, #0x48
	movs r3, #1
	movs r6, #1
_081E4418:
	mov r0, r8
	strh r0, [r1, #0x18]
	adds r0, r2, r5
	strh r4, [r0]
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	adds r2, #0x60
	subs r6, #1
	cmp r6, #0
	bge _081E4418
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E4440: .4byte 0x000002DF
_081E4444: .4byte 0x00005BE0
_081E4448: .4byte 0x00001454
_081E444C: .4byte 0x00000E6E
