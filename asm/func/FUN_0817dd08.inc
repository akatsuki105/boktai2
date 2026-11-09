	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r7, r0, #0
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r1, [sp]
	asrs r0, r1, #0x10
	adds r0, #0xdc
	lsls r0, r0, #0x10
	ldr r4, _0817DDDC @ =0x0000FFFF
	ands r4, r1
	orrs r4, r0
	str r4, [sp]
	ldr r6, _0817DDE0 @ =0x0203B400
	ldr r0, _0817DDE4 @ =0x030046B8
	mov sl, r0
	ldr r2, [r0]
	adds r2, #1
	ldr r5, _0817DDE8 @ =0x000003FF
	ands r2, r5
	lsls r0, r2, #1
	adds r0, r0, r6
	ldrh r3, [r0]
	mov r0, sp
	ldrh r1, [r0]
	subs r1, #0x10
	movs r0, #0x1f
	mov r8, r0
	mov r0, r8
	ands r3, r0
	adds r1, r1, r3
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _0817DDEC @ =0xFFFF0000
	mov sb, r3
	mov r0, sb
	ands r0, r4
	orrs r0, r1
	str r0, [sp]
	adds r2, #1
	ands r2, r5
	lsls r0, r2, #1
	adds r0, r0, r6
	ldrh r3, [r0]
	mov r0, sp
	ldrh r1, [r0, #4]
	subs r1, #0x10
	mov r0, r8
	ands r3, r0
	adds r1, r1, r3
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #4]
	mov r3, sb
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #4]
	adds r2, #1
	ands r2, r5
	lsls r0, r2, #1
	adds r0, r0, r6
	ldrh r3, [r0]
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrb r0, [r0]
	subs r0, #0x20
	movs r1, #0x3f
	ands r3, r1
	adds r4, r0, r3
	movs r3, #0xff
	adds r2, #1
	ands r2, r5
	mov r0, sl
	str r2, [r0]
	lsls r2, r2, #1
	adds r2, r2, r6
	ldrh r1, [r2]
	movs r0, #0xf
	ands r1, r0
	add r5, sp, #8
	ands r4, r3
	adds r6, r1, #0
	adds r6, #0xa
	ldr r1, _0817DDF0 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	mov r3, sl
	mov r8, r5
	cmp r0, #0
	blt _0817DDF4
	asrs r2, r0, #0xc
	b _0817DDFA
	.align 2, 0
_0817DDDC: .4byte 0x0000FFFF
_0817DDE0: .4byte 0x0203B400
_0817DDE4: .4byte 0x030046B8
_0817DDE8: .4byte 0x000003FF
_0817DDEC: .4byte 0xFFFF0000
_0817DDF0: .4byte gSineTable
_0817DDF4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0817DDFA:
	movs r0, #0
	strh r2, [r5]
	strh r0, [r5, #2]
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0817DE12
	asrs r0, r0, #0xc
	b _0817DE18
_0817DE12:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0817DE18:
	strh r0, [r5, #4]
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _0817DE48 @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r2, _0817DE4C @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	subs r0, #0x10
	mov r3, r8
	strh r0, [r3, #2]
	ldr r1, _0817DE50 @ =0x0000049C
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0817DE54
	movs r3, #7
	b _0817DE9C
	.align 2, 0
_0817DE48: .4byte 0x000003FF
_0817DE4C: .4byte 0x0203B400
_0817DE50: .4byte 0x0000049C
_0817DE54:
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0817DE60
	movs r3, #1
	b _0817DE9C
_0817DE60:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0817DE6C
	movs r3, #2
	b _0817DE9C
_0817DE6C:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0817DE78
	movs r3, #3
	b _0817DE9C
_0817DE78:
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0817DE84
	movs r3, #4
	b _0817DE9C
_0817DE84:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0817DE90
	movs r3, #5
	b _0817DE9C
_0817DE90:
	movs r0, #0x20
	ands r1, r0
	movs r3, #0
	cmp r1, #0
	beq _0817DE9C
	movs r3, #6
_0817DE9C:
	mov r0, sp
	mov r1, r8
	movs r2, #0x14
	bl Entity081ee2a0_SpawnDefault
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
