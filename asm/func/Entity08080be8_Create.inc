	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x24
	adds r6, r0, #0
	adds r7, r1, #0
	mov r8, r2
	adds r5, r3, #0
	movs r1, #0xcc
	lsls r1, r1, #1
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08080C54
	ldr r1, _08080C4C @ =Entity08080be8_Update
	ldr r2, _08080C50 @ =Entity08080be8_Destroy
	bl SetEntityRoutine
	str r5, [sp]
	ldr r0, [sp, #0x3c]
	str r0, [sp, #4]
	ldr r0, [sp, #0x40]
	str r0, [sp, #8]
	ldr r0, [sp, #0x44]
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x48]
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x4c]
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x50]
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x54]
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x58]
	str r0, [sp, #0x20]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	mov r3, r8
	bl Entity08080be8_Init
	cmp r0, #0
	bge _08080C54
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08080C56
	.align 2, 0
_08080C4C: .4byte Entity08080be8_Update
_08080C50: .4byte Entity08080be8_Destroy
_08080C54:
	adds r0, r4, #0
_08080C56:
	add sp, #0x24
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
