	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	str r0, [sp, #4]
	mov r8, r1
	adds r4, r2, #0
	mov sl, r3
	ldr r0, _080DCEE4 @ =0x0300016C
	ldr r5, [r0]
	cmp r5, #0
	bne _080DCEB2
	bl Entity080dd1f8_Create
	adds r5, r0, #0
	cmp r5, #0
	beq _080DCEDE
_080DCEB2:
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _080DCEE8 @ =0x030047A4
	ldr r1, _080DCEEC @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	bne _080DCEDE
	ldr r0, _080DCEF0 @ =0x03002BC0
	ldr r7, [r0]
	movs r0, #4
	ands r7, r0
	cmp r7, #0
	bne _080DCEDE
	adds r0, r5, #0
	bl FUN_080dc764
	adds r6, r0, #0
	cmp r6, #0
	bne _080DCEF4
_080DCEDE:
	movs r0, #0
	b _080DD0A2
	.align 2, 0
_080DCEE4: .4byte 0x0300016C
_080DCEE8: .4byte 0x030047A4
_080DCEEC: .4byte 0x030047A0
_080DCEF0: .4byte 0x03002BC0
_080DCEF4:
	movs r1, #0x97
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r2, #1
	mov sb, r2
	mov r3, sb
	strb r3, [r0]
	subs r1, #2
	adds r0, r6, r1
	strh r7, [r0]
	movs r3, #0x92
	lsls r3, r3, #1
	adds r2, r6, r3
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r2]
	str r1, [r2, #4]
	movs r1, #0x98
	lsls r1, r1, #1
	adds r0, r6, r1
	mov r2, sb
	strb r2, [r0]
	subs r3, #8
	adds r2, r6, r3
	mov r3, r8
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2]
	str r1, [r2, #4]
	movs r1, #0x9b
	lsls r1, r1, #1
	adds r0, r6, r1
	mov r2, sl
	strh r2, [r0]
	movs r3, #0x9c
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, [sp, #0x28]
	strh r0, [r1]
	movs r1, #0x9f
	lsls r1, r1, #1
	adds r0, r6, r1
	mov r2, sp
	ldrh r2, [r2, #0x2c]
	strh r2, [r0]
	subs r3, #6
	adds r0, r6, r3
	mov r1, sp
	ldrh r1, [r1, #0x2c]
	strh r1, [r0]
	ldr r2, _080DCFC8 @ =0x00000131
	adds r1, r6, r2
	movs r0, #0x1e
	strb r0, [r1]
	adds r3, #0xa
	adds r1, r6, r3
	ldr r0, [sp, #0x30]
	strh r0, [r1]
	ldr r1, _080DCFCC @ =0x0000013B
	adds r0, r6, r1
	mov r2, sb
	strb r2, [r0]
	mov r8, r6
	ldr r3, [sp, #4]
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
	adds r1, r5, #0
	adds r1, #0x18
	adds r0, r6, #0
	movs r2, #0
	bl AuxSprite_Add
	adds r4, r6, #0
	adds r4, #0x2c
	ldr r1, [r5, #0x34]
	str r7, [sp]
	adds r0, r4, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08236fac
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r6, #0x2c]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r4, #4]
	mov r1, sb
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	mov r2, sb
	ands r0, r2
	cmp r1, r0
	beq _080DCFD0
	ldr r0, [r6]
	movs r3, #4
	orrs r0, r3
	b _080DCFD8
	.align 2, 0
_080DCFC8: .4byte 0x00000131
_080DCFCC: .4byte 0x0000013B
_080DCFD0:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080DCFD8:
	str r0, [r6]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080DD002
	mov r1, r8
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	mov r2, r8
	str r0, [r2]
	b _080DD00E
_080DD002:
	mov r3, r8
	ldr r0, [r3]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
_080DD00E:
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080DD044 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _080DD07C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080DD048
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080DD03C
	ldrb r0, [r4, #5]
_080DD03C:
	subs r0, #1
	strh r0, [r4, #8]
	b _080DD058
	.align 2, 0
_080DD044: .4byte 0x0000FFFF
_080DD048:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080DD058
	strh r1, [r4, #8]
_080DD058:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080DD07C
	movs r0, #1
	strb r0, [r4, #7]
_080DD07C:
	mov r3, r8
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
	strb r1, [r3, #7]
	adds r0, r6, #0
	adds r0, #0xdc
	mov r1, r8
	adds r1, #0x1c
	movs r2, #0
	bl ParticleShadow_Init
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080dc650
	adds r0, r6, #0
_080DD0A2:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
