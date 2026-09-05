	push {r4, r5, r6, lr}
	sub sp, #8
	ldr r0, _08009A84 @ =0x0300003C
	ldr r6, [r0]
	cmp r6, #0
	beq _08009A7C
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r0, #0
	adds r0, r6, #0
	movs r2, #0
	bl FUN_0800922c
	adds r5, r0, #0
	cmp r5, #0
	bne _08009A88
_08009A7C:
	movs r0, #1
	rsbs r0, r0, #0
	b _08009AF6
	.align 2, 0
_08009A84: .4byte 0x0300003C
_08009A88:
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08009AD0
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _08009AC8 @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r4
	orrs r1, r0
	str r1, [sp]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _08009ACC @ =0x0000FFFF
	ldr r1, [sp]
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	b _08009ADA
	.align 2, 0
_08009AC8: .4byte 0xFFFF0000
_08009ACC: .4byte 0x0000FFFF
_08009AD0:
	ldr r1, _08009B00 @ =0xFFFF0000
	str r0, [sp]
	ldr r0, [sp, #4]
	ands r0, r1
	str r0, [sp, #4]
_08009ADA:
	adds r0, r6, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08009298
	ldr r1, [r5, #8]
	cmp r1, #0
	blt _08009AF6
	adds r0, r5, #0
	adds r0, #0x1c
	bl FUN_08241574
	adds r1, r0, #0
	str r1, [r5, #8]
_08009AF6:
	add sp, #8
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08009B00: .4byte 0xFFFF0000
