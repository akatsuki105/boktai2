	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	adds r6, r1, #0
	movs r0, #0x20
	adds r0, r0, r6
	mov sl, r0
	ldrb r0, [r6, #9]
	cmp r0, #0
	beq _0820ACE6
	movs r4, #0
	strb r4, [r6, #9]
	strb r4, [r6, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r6, #0
	movs r1, #5
	movs r2, #1
	movs r3, #1
	bl FUN_08041480
	strh r4, [r6, #0x20]
	mov r1, sl
	strh r4, [r1, #2]
_0820ACE6:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _0820ACFE
	b _0820AF8E
_0820ACFE:
	ldrh r4, [r6, #0x20]
	cmp r4, #1
	beq _0820AD46
	cmp r4, #1
	bgt _0820AD0E
	cmp r4, #0
	beq _0820AD18
	b _0820AF8E
_0820AD0E:
	cmp r4, #2
	beq _0820AD6E
	cmp r4, #3
	beq _0820AD96
	b _0820AF8E
_0820AD18:
	mov r1, sl
	ldrh r0, [r1, #2]
	adds r0, #1
	strh r0, [r1, #2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bhi _0820AD2A
	b _0820AF8E
_0820AD2A:
	movs r0, #4
	str r0, [sp]
	adds r0, r6, #0
	movs r1, #6
	movs r2, #2
	movs r3, #1
	bl FUN_08041480
	ldrh r0, [r6, #0x20]
	adds r0, #1
	strh r0, [r6, #0x20]
	mov r0, sl
	strh r4, [r0, #2]
	b _0820AF8E
_0820AD46:
	mov r1, sl
	ldrh r0, [r1, #2]
	adds r0, #1
	strh r0, [r1, #2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bhi _0820AD58
	b _0820AF8E
_0820AD58:
	movs r0, #4
	str r0, [sp]
	adds r0, r6, #0
	movs r1, #7
	movs r2, #2
	movs r3, #1
	bl FUN_08041480
	ldrh r0, [r6, #0x20]
	adds r0, #1
	b _0820AF86
_0820AD6E:
	mov r1, sl
	ldrh r0, [r1, #2]
	adds r0, #1
	strh r0, [r1, #2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _0820AD80
	b _0820AF8E
_0820AD80:
	movs r0, #4
	str r0, [sp]
	adds r0, r6, #0
	movs r1, #8
	movs r2, #2
	movs r3, #1
	bl FUN_08041480
	ldrh r0, [r6, #0x20]
	adds r0, #1
	b _0820AF86
_0820AD96:
	mov r0, sl
	ldrh r7, [r0, #2]
	cmp r7, #4
	beq _0820ADA0
	b _0820AF60
_0820ADA0:
	ldr r0, [r6, #0x64]
	ldr r1, [r6, #0x68]
	str r0, [sp, #0x1c]
	str r1, [sp, #0x20]
	add r0, sp, #0x1c
	ldrh r0, [r0]
	adds r0, #0xb4
	add r1, sp, #0x1c
	strh r0, [r1]
	ldr r4, _0820AFA0 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _0820AFA4 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _0820AFA8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	str r0, [sp]
	movs r0, #0xa
	str r0, [sp, #4]
	str r0, [sp, #8]
	movs r5, #5
	str r5, [sp, #0xc]
	movs r1, #8
	mov r8, r1
	str r1, [sp, #0x10]
	str r1, [sp, #0x14]
	str r5, [sp, #0x18]
	movs r0, #4
	movs r1, #0x26
	add r2, sp, #0x1c
	movs r3, #0
	bl Entity080146e0_SpawnAtAngle
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _0820AFA4 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _0820AFA8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	str r0, [sp]
	movs r0, #0xa
	str r0, [sp, #4]
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	mov r1, r8
	str r1, [sp, #0x10]
	str r1, [sp, #0x14]
	str r5, [sp, #0x18]
	movs r0, #4
	movs r1, #0x26
	add r2, sp, #0x1c
	movs r3, #0x40
	bl Entity080146e0_SpawnAtAngle
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _0820AFA4 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _0820AFA8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	str r0, [sp]
	movs r0, #0xa
	str r0, [sp, #4]
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	mov r1, r8
	str r1, [sp, #0x10]
	str r1, [sp, #0x14]
	str r5, [sp, #0x18]
	movs r0, #4
	movs r1, #0x26
	add r2, sp, #0x1c
	movs r3, #0x80
	bl Entity080146e0_SpawnAtAngle
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _0820AFA4 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _0820AFA8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	str r0, [sp]
	movs r0, #0xa
	str r0, [sp, #4]
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	mov r1, r8
	str r1, [sp, #0x10]
	str r1, [sp, #0x14]
	str r5, [sp, #0x18]
	movs r0, #4
	movs r1, #0x26
	add r2, sp, #0x1c
	movs r3, #0xc0
	bl Entity080146e0_SpawnAtAngle
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _0820AFA4 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _0820AFA8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	str r7, [sp, #8]
	str r7, [sp, #0xc]
	str r7, [sp, #0x10]
	movs r1, #0xe
	mov sb, r1
	str r1, [sp, #0x14]
	str r7, [sp, #0x18]
	movs r0, #2
	movs r1, #0x26
	add r2, sp, #0x1c
	movs r3, #0
	bl Entity080146e0_SpawnAtAngle
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _0820AFA4 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _0820AFA8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	str r7, [sp, #8]
	str r7, [sp, #0xc]
	str r7, [sp, #0x10]
	mov r1, sb
	str r1, [sp, #0x14]
	str r7, [sp, #0x18]
	movs r0, #2
	movs r1, #0x26
	add r2, sp, #0x1c
	movs r3, #0x40
	bl Entity080146e0_SpawnAtAngle
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _0820AFA4 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _0820AFA8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	str r7, [sp, #8]
	str r7, [sp, #0xc]
	str r7, [sp, #0x10]
	mov r1, sb
	str r1, [sp, #0x14]
	str r7, [sp, #0x18]
	movs r0, #2
	movs r1, #0x26
	add r2, sp, #0x1c
	movs r3, #0x80
	bl Entity080146e0_SpawnAtAngle
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _0820AFA4 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _0820AFA8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	str r7, [sp, #8]
	str r7, [sp, #0xc]
	str r7, [sp, #0x10]
	mov r1, sb
	str r1, [sp, #0x14]
	str r7, [sp, #0x18]
	movs r0, #2
	movs r1, #0x26
	add r2, sp, #0x1c
	movs r3, #0xc0
	bl Entity080146e0_SpawnAtAngle
	ldr r0, _0820AFAC @ =0x00000395
	bl PlaySound_082406e0
_0820AF60:
	mov r1, sl
	ldrh r0, [r1, #2]
	adds r0, #1
	strh r0, [r1, #2]
	adds r0, r6, #0
	adds r0, #0xd0
	bl SpriteHolder_IsAnimEnded
	cmp r0, #0
	beq _0820AF8E
	movs r0, #4
	str r0, [sp]
	adds r0, r6, #0
	movs r1, #6
	movs r2, #2
	movs r3, #1
	bl FUN_08041480
	movs r0, #1
_0820AF86:
	strh r0, [r6, #0x20]
	movs r0, #0
	mov r1, sl
	strh r0, [r1, #2]
_0820AF8E:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0820AFA0: .4byte 0x030046B8
_0820AFA4: .4byte 0x000003FF
_0820AFA8: .4byte 0x0203B400
_0820AFAC: .4byte 0x00000395
