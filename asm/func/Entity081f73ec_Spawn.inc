	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x18
	adds r5, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	mov r8, r3
	ldr r0, _081F72A4 @ =0x030001FC
	ldr r0, [r0]
	cmp r0, #0
	bne _081F7268
	bl Entity081f73ec_Create
	cmp r0, #0
	beq _081F7306
_081F7268:
	bl Entity081f73ec_AllocElem
	adds r4, r0, #0
	cmp r4, #0
	beq _081F7306
	ldr r1, _081F72A8 @ =0x000006E6
	adds r0, r4, r1
	movs r1, #0
	movs r3, #1
	strb r3, [r0]
	ldr r0, _081F72AC @ =0x000006E4
	adds r2, r4, r0
	strh r1, [r2]
	subs r0, #0xb
	adds r1, r4, r0
	ldr r0, [sp, #0x40]
	strb r0, [r1]
	ldr r0, _081F72B0 @ =0x000006EB
	adds r1, r4, r0
	ldr r0, [sp, #0x34]
	strb r0, [r1]
	ldr r1, _081F72B4 @ =0x000006EA
	adds r0, r4, r1
	strb r3, [r0]
	ldr r0, [sp, #0x44]
	cmp r0, #0
	bne _081F72B8
	strh r3, [r2]
	b _081F72BC
	.align 2, 0
_081F72A4: .4byte 0x030001FC
_081F72A8: .4byte 0x000006E6
_081F72AC: .4byte 0x000006E4
_081F72B0: .4byte 0x000006EB
_081F72B4: .4byte 0x000006EA
_081F72B8:
	movs r0, #2
	strh r0, [r2]
_081F72BC:
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldr r2, [sp, #0x10]
	asrs r1, r2, #0x10
	ldr r0, _081F7314 @ =0xFFFFFF00
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _081F7318 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r1, _081F731C @ =0x0000D636
	ldr r2, _081F7320 @ =0x0000C102
	adds r0, r4, #0
	movs r3, #0
	bl Entity081f73ec_InitSegs
	adds r0, r4, #0
	add r1, sp, #0x10
	bl Entity081f73ec_SetAllSegPos
	ldr r0, [sp, #0x30]
	str r0, [sp]
	ldr r0, [sp, #0x48]
	str r0, [sp, #4]
	ldr r0, [sp, #0x4c]
	str r0, [sp, #8]
	ldr r0, [sp, #0x50]
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	mov r3, r8
	bl Entity081f73ec_InitHitbox
_081F7306:
	add sp, #0x18
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081F7314: .4byte 0xFFFFFF00
_081F7318: .4byte 0x0000FFFF
_081F731C: .4byte 0x0000D636
_081F7320: .4byte 0x0000C102
