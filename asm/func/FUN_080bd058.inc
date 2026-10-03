	push {r4, r5, r6, lr}
	sub sp, #0x24
	adds r6, r0, #0
	ldr r1, _080BD078 @ =0x00001785
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BD080
	ldr r2, _080BD07C @ =0x00001787
	adds r0, r6, r2
	ldrb r0, [r0]
	mov r1, sp
	bl FUN_08242b14
	b _080BD0E8
	.align 2, 0
_080BD078: .4byte 0x00001785
_080BD07C: .4byte 0x00001787
_080BD080:
	cmp r0, #7
	bhi _080BD0D8
	ldr r2, _080BD0C8 @ =0x08DA9E68
	ldr r3, _080BD0CC @ =0x00001787
	adds r1, r6, r3
	ldr r4, _080BD0D0 @ =0x00001654
	adds r0, r6, r4
	ldrb r0, [r0]
	lsls r0, r0, #4
	subs r0, #0x10
	ldrb r1, [r1]
	adds r0, r0, r1
	ldr r3, _080BD0D4 @ =0x0000165C
	adds r1, r6, r3
	adds r1, r1, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r1, r0, #3
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r0, sp
	adds r1, r1, r2
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
	mov r1, sp
	movs r0, #0
	strb r0, [r1, #0x18]
	adds r0, r6, #0
	bl FUN_080bd01c
	b _080BD0E8
	.align 2, 0
_080BD0C8: .4byte 0x08DA9E68
_080BD0CC: .4byte 0x00001787
_080BD0D0: .4byte 0x00001654
_080BD0D4: .4byte 0x0000165C
_080BD0D8:
	mov r1, sp
	ldr r0, _080BD108 @ =0x08DA9E68
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
_080BD0E8:
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, #0
	bne _080BD10C
	movs r4, #0xce
	lsls r4, r4, #4
	adds r0, r6, r4
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	bl TextBox_Close
	bl FUN_08049e5c
	b _080BD162
	.align 2, 0
_080BD108: .4byte 0x08DA9E68
_080BD10C:
	movs r0, #0xce
	lsls r0, r0, #4
	adds r2, r6, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080BD174 @ =0x00000CD8
	adds r4, r6, r1
	adds r5, r6, #0
	adds r5, #0x38
	mov r0, sp
	bl FUN_08094e70
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #1
	bl MainSprite_SetPose
	ldr r2, _080BD178 @ =0x00001644
	adds r4, r6, r2
	ldr r0, [r4]
	bl TextBox_Start
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x1c
	movs r3, #2
	bl TextBox_SetRect
	ldr r3, _080BD17C @ =0x0000164C
	adds r1, r6, r3
	mov r0, sp
	bl FUN_08094d1c
	ldr r1, [r4]
	mov r0, sp
	bl FUN_08094d48
_080BD162:
	adds r0, r6, #0
	mov r1, sp
	bl FUN_080bcf04
	add sp, #0x24
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080BD174: .4byte 0x00000CD8
_080BD178: .4byte 0x00001644
_080BD17C: .4byte 0x0000164C
