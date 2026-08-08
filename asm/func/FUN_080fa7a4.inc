	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r7, r0, #0
	ldr r0, _080FA82C @ =0x7FFFFFFF
	str r0, [sp, #8]
	movs r1, #1
	rsbs r1, r1, #0
	str r1, [sp, #0xc]
	ldr r0, _080FA830 @ =0x03002C68
	ldr r0, [r0]
	str r1, [sp, #0x10]
	cmp r0, #0
	beq _080FA7CA
	ldrh r0, [r0, #0x1a]
	str r0, [sp, #0x10]
_080FA7CA:
	movs r6, #0
	ldr r2, [sp, #0x10]
	cmp r6, r2
	bge _080FA8CC
	mov r5, sp
	ldr r3, _080FA834 @ =0x03002BE0
	mov r8, r3
	mov sl, r6
	movs r0, #8
	adds r0, r0, r7
	mov sb, r0
_080FA7E0:
	mov r1, r8
	ldr r2, [r1]
	cmp r2, #0
	beq _080FA8BE
	movs r0, #8
	ldr r1, _080FA838 @ =0x03002BC0
	add r1, sl
	ldr r1, [r1]
	ands r1, r0
	cmp r1, #0
	bne _080FA8BE
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r2, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _080FA8BE
	ldrh r0, [r2, #0x2c]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r2, #0x30]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _080FA826
	cmp r1, #0
	blt _080FA826
	ldr r0, _080FA83C @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _080FA826
	ldr r0, _080FA840 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080FA844
_080FA826:
	movs r4, #0
	b _080FA852
	.align 2, 0
_080FA82C: .4byte 0x7FFFFFFF
_080FA830: .4byte 0x03002C68
_080FA834: .4byte 0x03002BE0
_080FA838: .4byte 0x03002BC0
_080FA83C: .4byte 0x030046A8
_080FA840: .4byte 0x030046AC
_080FA844:
	ldr r0, _080FA864 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r3
_080FA852:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080FA868
	adds r0, #4
	b _080FA874
	.align 2, 0
_080FA864: .4byte 0x030046A4
_080FA868:
	ldr r0, _080FA8D8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080FA874:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	bne _080FA8BE
	mov r2, r8
	ldr r0, [r2]
	adds r2, r0, #0
	adds r2, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r7, #8]
	subs r0, r0, r1
	strh r0, [r5]
	ldrh r0, [r2, #2]
	mov r3, sb
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	movs r1, #0
	ldrsh r0, [r5, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r5, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	ldr r0, [sp, #8]
	cmp r1, r0
	bge _080FA8BE
	str r1, [sp, #8]
	str r6, [sp, #0xc]
_080FA8BE:
	movs r1, #4
	add r8, r1
	add sl, r1
	adds r6, #1
	ldr r2, [sp, #0x10]
	cmp r6, r2
	blt _080FA7E0
_080FA8CC:
	ldr r3, [sp, #0xc]
	cmp r3, #0
	bge _080FA8DC
	movs r0, #0
	b _080FA942
	.align 2, 0
_080FA8D8: .4byte 0x030046A4
_080FA8DC:
	ldr r0, _080FA90C @ =0x03002BE0
	ldr r2, [sp, #0xc]
	lsls r1, r2, #2
	adds r1, r1, r0
	ldr r3, _080FA910 @ =0x000004A4
	adds r0, r7, r3
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	ldr r0, [r1]
	adds r4, r0, #0
	adds r4, #0x2c
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _080FA914
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r7, r1
	b _080FA938
	.align 2, 0
_080FA90C: .4byte 0x03002BE0
_080FA910: .4byte 0x000004A4
_080FA914:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _080FA932
	cmp r0, #2
	beq _080FA940
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
	b _080FA940
_080FA932:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
_080FA938:
	ldr r1, _080FA954 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_080FA940:
	movs r0, #1
_080FA942:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080FA954: .4byte 0xFFFFFDFF
