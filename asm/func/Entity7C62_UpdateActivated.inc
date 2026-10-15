	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #1
	bls _080A3D02
	subs r0, #2
	b _080A3D04
_080A3D02:
	movs r0, #0
_080A3D04:
	strh r0, [r1]
	adds r2, r4, #0
	adds r2, #0xae
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r1, [r0]
	ldrh r2, [r2]
	adds r1, r1, r2
	adds r2, r4, #0
	adds r2, #0x82
	strh r1, [r2]
	ldrh r0, [r0]
	cmp r0, #0
	bne _080A3D8A
	ldr r0, _080A3D94 @ =0x03002BE0
	ldr r0, [r0]
	movs r3, #0xdf
	lsls r3, r3, #2
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A3D8A
	ldr r0, [r4, #0x64]
	ldr r1, _080A3D98 @ =0xFFFFFDFF
	ands r0, r1
	str r0, [r4, #0x64]
	adds r1, r4, #0
	adds r1, #0x6b
	movs r0, #3
	strb r0, [r1]
	adds r2, #0x32
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r1, _080A3D9C @ =Entity7C62_UpdateDone
	adds r0, r4, #0
	bl Entity7C62_SetUpdateCallback
	movs r1, #0x84
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _080A3D8A
	ldr r1, _080A3DA0 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	str r0, [sp, #8]
	add r1, sp, #8
	mov r3, sp
	str r3, [r1, #4]
	movs r3, #0x82
	lsls r3, r3, #1
	adds r0, r4, r3
	ldrh r0, [r0]
	str r0, [sp]
	adds r3, #2
	adds r0, r4, r3
	ldrh r0, [r0]
	str r0, [sp, #4]
	adds r0, r2, #0
	bl VM_ExecByID
_080A3D8A:
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A3D94: .4byte 0x03002BE0
_080A3D98: .4byte 0xFFFFFDFF
_080A3D9C: .4byte Entity7C62_UpdateDone
_080A3DA0: .4byte 0xFFFF0000
