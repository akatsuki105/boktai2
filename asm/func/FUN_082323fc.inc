	push {r4, r5, lr}
	ldr r4, _08232408 @ =0xFFFFFDF8
	add sp, r4
	adds r4, r0, #0
	add r5, sp, #0x204
	b _0823242A
	.align 2, 0
_08232408: .4byte 0xFFFFFDF8
_0823240C:
	cmp r0, #7
	bne _0823241A
	ldr r1, [r5]
	mov r0, sp
	bl FUN_0823226c
	b _0823242A
_0823241A:
	cmp r0, #0xe
	bne _0823242A
	ldr r1, [r5]
	b _08232424
_08232422:
	adds r1, #1
_08232424:
	ldrb r0, [r1]
	cmp r0, #0
	bne _08232422
_0823242A:
	cmp r4, #0
	beq _08232442
	adds r0, r4, #0
	add r1, sp, #0x200
	add r2, sp, #0x204
	bl VM_Step
	adds r4, r0, #0
	add r0, sp, #0x200
	ldr r0, [r0]
	cmp r0, #0
	bne _0823240C
_08232442:
	movs r0, #0
	movs r3, #0x82
	lsls r3, r3, #2
	add sp, r3
	pop {r4, r5}
	pop {r1}
	bx r1
