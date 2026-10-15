	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r7, r0, #0
	ldr r0, _080529E0 @ =0x0300011C
	str r7, [r0]
	movs r0, #0x73
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080529DA
	bl FUN_0823d340
	ldr r2, _080529E4 @ =0x000008B4
	adds r1, r7, r2
	str r0, [r1]
	cmp r0, #0
	bne _080529E8
_080529DA:
	movs r0, #1
	rsbs r0, r0, #0
	b _08052AC6
	.align 2, 0
_080529E0: .4byte 0x0300011C
_080529E4: .4byte 0x000008B4
_080529E8:
	ldr r5, _08052AD8 @ =0x0000CB05
	ldr r1, _08052ADC @ =0x0000DCC1
	adds r0, r5, #0
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	beq _080529DA
	adds r1, r7, #0
	adds r1, #0x30
	adds r0, r2, #0
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	adds r4, r7, #0
	adds r4, #0x30
	adds r0, r4, #0
	adds r1, r2, #0
	bl OpenMainSpriteFile
	ldr r1, _08052AE0 @ =0x0000D27A
	adds r0, r5, #0
	bl GetFile
	adds r2, r0, #0
	mov sb, r4
	cmp r2, #0
	beq _080529DA
	adds r0, r7, #0
	adds r0, #0x50
	adds r1, r2, #0
	ldm r1!, {r3, r5, r6}
	stm r0!, {r3, r5, r6}
	ldm r1!, {r4, r5, r6}
	stm r0!, {r4, r5, r6}
	ldm r1!, {r3, r4}
	stm r0!, {r3, r4}
	adds r4, r7, #0
	adds r4, #0x50
	adds r0, r4, #0
	adds r1, r2, #0
	bl OpenMainSpriteFile
	adds r6, r7, #0
	adds r6, #0x70
	mov sl, r4
	movs r4, #0
	movs r5, #0x14
_08052A4E:
	str r4, [sp]
	str r4, [sp, #4]
	movs r0, #0x3c
	mov r8, r0
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	adds r0, r6, #0
	mov r1, sb
	movs r2, #0
	ldr r3, _08052AE4 @ =0x00002011
	bl MainSprite_Add
	subs r5, #1
	adds r6, #0x60
	cmp r5, #0
	bge _08052A4E
	movs r1, #0x85
	lsls r1, r1, #4
	adds r6, r7, r1
	ldr r3, _08052AE4 @ =0x00002011
	movs r5, #0
	str r5, [sp]
	str r5, [sp, #4]
	mov r2, r8
	str r2, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r6, #0
	mov r1, sl
	movs r2, #0
	bl MainSprite_Add
	ldr r3, _08052AE8 @ =0x000008C8
	adds r4, r7, r3
	movs r0, #0
	bl FUN_0804f814
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x10
	bl CopyMemory
	ldr r6, _08052AEC @ =0x000008D8
	adds r4, r7, r6
	movs r0, #1
	bl FUN_0804f814
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x10
	bl CopyMemory
	strb r5, [r7, #0x1c]
	movs r0, #1
	strb r0, [r7, #0x1d]
	str r5, [r7, #0x18]
	movs r1, #0x8b
	lsls r1, r1, #4
	adds r0, r7, r1
	str r5, [r0]
	movs r0, #0
_08052AC6:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08052AD8: .4byte 0x0000CB05
_08052ADC: .4byte 0x0000DCC1
_08052AE0: .4byte 0x0000D27A
_08052AE4: .4byte 0x00002011
_08052AE8: .4byte 0x000008C8
_08052AEC: .4byte 0x000008D8
