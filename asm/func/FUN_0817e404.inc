	push {r4, r5, lr}
	sub sp, #0x18
	adds r3, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r5, [r0]
	ldr r2, _0817E444 @ =0x000007AE
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _0817E500
	movs r1, #8
	ldrsh r0, [r3, r1]
	str r0, [sp]
	movs r2, #0xa
	ldrsh r0, [r3, r2]
	str r0, [sp, #4]
	movs r1, #0xc
	ldrsh r0, [r3, r1]
	str r0, [sp, #8]
	movs r2, #0x80
	lsls r2, r2, #2
	ldr r0, _0817E448 @ =0x00000898
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _0817E44C
	movs r0, #1
	b _0817E44E
	.align 2, 0
_0817E444: .4byte 0x000007AE
_0817E448: .4byte 0x00000898
_0817E44C:
	movs r0, #0
_0817E44E:
	cmp r0, #0
	beq _0817E474
	ldr r1, _0817E46C @ =0x000007A4
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	str r0, [sp, #0xc]
	adds r0, r3, #0
	movs r1, #0
	bl FUN_0817e004
	ldr r1, _0817E470 @ =0xFFFFFDFF
	b _0817E4D8
	.align 2, 0
_0817E46C: .4byte 0x000007A4
_0817E470: .4byte 0xFFFFFDFF
_0817E474:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0817E484
	movs r0, #1
	b _0817E486
_0817E484:
	movs r0, #0
_0817E486:
	cmp r0, #0
	beq _0817E4AC
	ldr r2, _0817E4A4 @ =0x000007A5
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	str r0, [sp, #0xc]
	adds r0, r3, #0
	movs r1, #1
	bl FUN_0817e004
	ldr r1, _0817E4A8 @ =0xFFFFFBFF
	b _0817E4D8
	.align 2, 0
_0817E4A4: .4byte 0x000007A5
_0817E4A8: .4byte 0xFFFFFBFF
_0817E4AC:
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0817E4BC
	movs r0, #1
	b _0817E4BE
_0817E4BC:
	movs r0, #0
_0817E4BE:
	cmp r0, #0
	beq _0817E4DE
	ldr r1, _0817E508 @ =0x000007A6
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	str r0, [sp, #0xc]
	adds r0, r3, #0
	movs r1, #2
	bl FUN_0817e004
	ldr r1, _0817E50C @ =0xFFFFF7FF
_0817E4D8:
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
_0817E4DE:
	ldr r1, _0817E510 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	str r0, [sp, #0x10]
	add r1, sp, #0x10
	mov r2, sp
	str r2, [r1, #4]
	ldr r2, _0817E514 @ =0x000007AE
	adds r0, r5, r2
	ldrh r0, [r0]
	bl VM_ExecByID
	ldr r0, _0817E518 @ =0x000002B7
	bl PlaySound_082406e0
_0817E500:
	add sp, #0x18
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0817E508: .4byte 0x000007A6
_0817E50C: .4byte 0xFFFFF7FF
_0817E510: .4byte 0xFFFF0000
_0817E514: .4byte 0x000007AE
_0817E518: .4byte 0x000002B7
