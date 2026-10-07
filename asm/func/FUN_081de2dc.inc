	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	bl FUN_081dd9d4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081DE2F0
	movs r0, #0
	strh r0, [r4, #0x2e]
_081DE2F0:
	mov r0, sp
	bl FUN_08238e48
	adds r1, r0, #0
	ldr r0, [r4, #0x4c]
	cmp r0, #0
	blt _081DE324
	cmp r1, #0
	blt _081DE324
	lsls r0, r0, #1
	add r0, sp
	ldrh r1, [r0]
	ldr r0, _081DE31C @ =0x0000FFFF
	cmp r1, r0
	beq _081DE324
	ldr r2, _081DE320 @ =FUN_081de360
	adds r0, r4, #0
	movs r1, #4
	bl Entity9A9F_SetState
	b _081DE352
	.align 2, 0
_081DE31C: .4byte 0x0000FFFF
_081DE320: .4byte FUN_081de360
_081DE324:
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bls _081DE352
	ldr r2, _081DE35C @ =FUN_081de250
	adds r0, r4, #0
	movs r1, #2
	bl Entity9A9F_SetState
	bl FUN_08238bf4
	adds r1, r4, #0
	adds r1, #0x68
	movs r2, #0
	adds r0, r4, #0
	adds r0, #0x6b
_081DE34A:
	strb r2, [r0]
	subs r0, #1
	cmp r0, r1
	bge _081DE34A
_081DE352:
	movs r0, #0
	add sp, #8
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081DE35C: .4byte FUN_081de250
