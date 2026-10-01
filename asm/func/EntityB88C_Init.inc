	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x18
	adds r6, r0, #0
	movs r0, #0x72
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0804B086
	bl FUN_0823d340
	movs r2, #0xa0
	lsls r2, r2, #2
	adds r1, r6, r2
	str r0, [r1]
	cmp r0, #0
	bne _0804B08C
_0804B086:
	movs r0, #1
	rsbs r0, r0, #0
	b _0804B202
_0804B08C:
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0804B0AA
	adds r4, r6, #0
	adds r4, #0x18
	movs r5, #3
_0804B09C:
	bl VM_GetValue
	stm r4!, {r0}
	subs r5, #1
	cmp r5, #0
	bge _0804B09C
	b _0804B0BC
_0804B0AA:
	adds r1, r6, #0
	adds r1, #0x18
	movs r2, #0
	adds r0, r6, #0
	adds r0, #0x24
_0804B0B4:
	str r2, [r0]
	subs r0, #4
	cmp r0, r1
	bge _0804B0B4
_0804B0BC:
	movs r0, #0x6c
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r5, r0, #0
	ldr r0, _0804B10C @ =0x0000CB05
	ldr r1, _0804B110 @ =0x0000DCC1
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	beq _0804B086
	adds r1, r6, #0
	adds r1, #0x38
	adds r0, r2, #0
	ldm r0!, {r3, r4, r7}
	stm r1!, {r3, r4, r7}
	ldm r0!, {r3, r4, r7}
	stm r1!, {r3, r4, r7}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	adds r4, r6, #0
	adds r4, #0x38
	adds r0, r4, #0
	adds r1, r2, #0
	bl OpenMainSpriteFile
	movs r0, #0
	str r0, [r6, #0x34]
	ldr r0, _0804B114 @ =gSystemSaveData
	ldr r0, [r0]
	ldr r1, [r0, #0x10]
	ldr r0, _0804B118 @ =0x0000369F
	mov sb, r4
	cmp r1, r0
	bne _0804B11C
	adds r1, r6, #0
	adds r1, #0x2c
	movs r0, #3
	b _0804B122
	.align 2, 0
_0804B10C: .4byte 0x0000CB05
_0804B110: .4byte 0x0000DCC1
_0804B114: .4byte gSystemSaveData
_0804B118: .4byte 0x0000369F
_0804B11C:
	adds r1, r6, #0
	adds r1, #0x2c
	movs r0, #2
_0804B122:
	strb r0, [r1]
	ldr r0, _0804B138 @ =0x030000D4
	ldr r0, [r0]
	adds r3, r6, #0
	adds r3, #0x2a
	strb r0, [r3]
	lsls r0, r0, #0x18
	cmp r0, #0
	bge _0804B13C
	movs r0, #0
	b _0804B148
	.align 2, 0
_0804B138: .4byte 0x030000D4
_0804B13C:
	movs r0, #0
	ldrsb r0, [r3, r0]
	ldrb r2, [r1]
	cmp r0, r2
	blt _0804B14A
	subs r0, r2, #1
_0804B148:
	strb r0, [r3]
_0804B14A:
	adds r2, r6, #0
	adds r2, #0x2b
	movs r0, #0xff
	strb r0, [r2]
	cmp r5, #0
	beq _0804B168
	movs r0, #0
	adds r1, r6, #0
	adds r1, #0x28
	strb r0, [r1]
	subs r2, #2
	movs r1, #1
	strb r1, [r2]
	str r0, [r6, #0x34]
	b _0804B18A
_0804B168:
	ldrb r1, [r1]
	cmp r1, #3
	bne _0804B17A
	adds r0, r6, #0
	adds r0, #0x28
	strb r1, [r0]
	adds r1, r6, #0
	adds r1, #0x29
	b _0804B184
_0804B17A:
	movs r0, #2
	adds r1, r6, #0
	adds r1, #0x28
	strb r0, [r1]
	adds r1, #1
_0804B184:
	movs r0, #1
	strb r0, [r1]
	str r5, [r6, #0x34]
_0804B18A:
	ldr r2, _0804B210 @ =0xFFFF0000
	movs r1, #0
	str r1, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	str r0, [sp, #0x14]
	ldr r0, _0804B214 @ =0x085AB564
	str r0, [r6, #0x30]
	adds r2, r6, #0
	adds r2, #0x2f
	movs r0, #3
	strb r0, [r2]
	adds r0, r6, #0
	adds r0, #0x2d
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	movs r7, #0xbe
	lsls r7, r7, #1
	adds r0, r6, r7
	ldr r1, _0804B218 @ =0x03003584
	ldr r1, [r1]
	ldr r2, _0804B21C @ =0x00005260
	adds r1, r1, r2
	movs r2, #0x80
	lsls r2, r2, #1
	bl CopyMemory
	adds r4, r6, #0
	adds r4, #0x58
	movs r3, #0
	mov r8, r3
	movs r7, #0xd8
	lsls r7, r7, #0xd
	movs r5, #2
_0804B1D0:
	lsrs r2, r7, #0x10
	mov r0, r8
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r0, r4, #0
	mov r1, sb
	movs r3, #0x11
	bl MainSprite_Add
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r6, r2
	str r0, [r4, #0x48]
	movs r3, #0x80
	lsls r3, r3, #0xa
	adds r7, r7, r3
	subs r5, #1
	adds r4, #0x60
	cmp r5, #0
	bge _0804B1D0
	movs r0, #0
_0804B202:
	add sp, #0x18
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0804B210: .4byte 0xFFFF0000
_0804B214: .4byte 0x085AB564
_0804B218: .4byte 0x03003584
_0804B21C: .4byte 0x00005260
