	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x24
	adds r7, r0, #0
	mov sb, r1
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r0, _0810A710 @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810A714
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810A716
	.align 2, 0
_0810A710: .4byte 0x0000046D
_0810A714:
	movs r0, #0
_0810A716:
	cmp r0, #0
	beq _0810A72A
	adds r0, r7, #0
	movs r1, #0x15
	bl Enemy_PlayAnim
	ldr r1, _0810A754 @ =0x00000725
	add r1, r8
	movs r0, #0x48
	strb r0, [r1]
_0810A72A:
	ldr r0, _0810A754 @ =0x00000725
	add r0, r8
	add r3, sp, #0xc
	ldrb r4, [r7, #5]
	ldrb r5, [r0]
	ldr r2, _0810A758 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	adds r6, r3, #0
	cmp r0, #0
	blt _0810A75C
	asrs r1, r0, #0xc
	b _0810A762
	.align 2, 0
_0810A754: .4byte 0x00000725
_0810A758: .4byte gSineTable
_0810A75C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0810A762:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _0810A77A
	asrs r0, r0, #0xc
	b _0810A780
_0810A77A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0810A780:
	strh r0, [r3, #4]
	ldrh r0, [r6]
	ldrh r1, [r7, #0x10]
	adds r0, r0, r1
	strh r0, [r7, #0x10]
	add r0, sp, #0xc
	ldrh r0, [r0, #4]
	ldrh r1, [r7, #0x14]
	adds r0, r0, r1
	strh r0, [r7, #0x14]
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	mov r0, sb
	movs r1, #4
	bl Mod
	cmp r0, #0
	bne _0810A810
	ldr r0, _0810A7C0 @ =0x00000725
	add r0, r8
	ldrb r0, [r0]
	cmp r0, #0
	blt _0810A7C4
	asrs r1, r0, #1
	b _0810A7CA
	.align 2, 0
_0810A7C0: .4byte 0x00000725
_0810A7C4:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_0810A7CA:
	ldr r0, _0810A864 @ =0x00000725
	add r0, r8
	movs r6, #0
	strb r1, [r0]
	ldr r3, _0810A868 @ =0xFFFF0000
	ldr r0, [sp, #0x14]
	ands r0, r3
	movs r2, #0x52
	orrs r0, r2
	ldr r1, _0810A86C @ =0x0000FFFF
	ands r0, r1
	str r0, [sp, #0x14]
	add r4, sp, #0x14
	ldr r0, [r4, #4]
	ands r0, r3
	orrs r0, r2
	str r0, [r4, #4]
	add r5, sp, #0x1c
	str r6, [sp, #8]
	add r0, sp, #8
	adds r1, r5, #0
	ldr r2, _0810A870 @ =0x05000002
	bl CpuSet
	adds r0, r7, #0
	adds r0, #8
	movs r1, #2
	str r1, [sp]
	movs r1, #4
	str r1, [sp, #4]
	adds r1, r5, #0
	adds r2, r4, #0
	movs r3, #1
	bl DustManager_Spawn
_0810A810:
	movs r0, #0xd5
	lsls r0, r0, #3
	add r0, r8
	bl Hitbox_Register
	ldr r1, _0810A874 @ =0x0000046E
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0810A854
	ldr r0, _0810A864 @ =0x00000725
	add r0, r8
	ldrb r4, [r0]
	cmp r4, #0
	bne _0810A854
	ldr r3, _0810A878 @ =Skeleton_StateDashEnd
	movs r2, #0x29
	ldr r0, _0810A87C @ =0x0000046D
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0810A880 @ =0x0000046B
	adds r0, r7, r1
	strb r4, [r0]
	adds r1, #0xe8
	adds r0, r7, r1
	strb r2, [r0]
	adds r1, #0x25
	adds r0, r7, r1
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r4, [r0]
_0810A854:
	add sp, #0x24
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0810A864: .4byte 0x00000725
_0810A868: .4byte 0xFFFF0000
_0810A86C: .4byte 0x0000FFFF
_0810A870: .4byte 0x05000002
_0810A874: .4byte 0x0000046E
_0810A878: .4byte Skeleton_StateDashEnd
_0810A87C: .4byte 0x0000046D
_0810A880: .4byte 0x0000046B
