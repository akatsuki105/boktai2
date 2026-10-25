	push {r4, lr}
	sub sp, #0xc
	adds r4, r1, #0
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _082060DE
	movs r0, #0
	strb r0, [r4, #9]
	strb r0, [r4, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #8
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
	ldr r0, [r4, #0x64]
	ldr r1, [r4, #0x68]
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldr r2, [sp, #4]
	asrs r1, r2, #0x10
	movs r0, #0x8c
	lsls r0, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _0820610C @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	add r0, sp, #4
	movs r1, #0
	bl Entity081f7de4_Spawn
	add r0, sp, #4
	movs r1, #0x80
	bl Entity081f7de4_Spawn
	ldr r0, _08206110 @ =0x000003CF
	bl PlaySound_082406e0
	ldr r0, _08206114 @ =0x000002D2
	bl PlaySound_082406e0
_082060DE:
	movs r0, #0x80
	lsls r0, r0, #5
	ldrh r1, [r4, #0xe]
	orrs r0, r1
	strh r0, [r4, #0xe]
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _08206102
	bl Entity081f7de4_RemoveAll
_08206102:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0820610C: .4byte 0x0000FFFF
_08206110: .4byte 0x000003CF
_08206114: .4byte 0x000002D2
