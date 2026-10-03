	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	adds r7, r0, #0
	movs r1, #0
	ldr r2, _0809B84C @ =0xFFFF0000
	movs r4, #0
	str r1, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	str r0, [sp, #0x14]
	ldr r2, _0809B850 @ =0x00000F64
	adds r0, r7, r2
	adds r6, r7, #0
	adds r6, #0x60
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #0x3c
	mov r8, r1
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0x29
	movs r3, #0xb0
	bl MainSprite_Add
	ldr r1, _0809B854 @ =0x00000FC4
	adds r0, r7, r1
	str r4, [sp]
	str r4, [sp, #4]
	mov r2, r8
	str r2, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0x89
	movs r3, #0xb1
	bl MainSprite_Add
	ldr r2, _0809B858 @ =0x00001024
	adds r0, r7, r2
	str r4, [sp]
	str r4, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0x8a
	movs r3, #0xb1
	bl MainSprite_Add
	ldr r1, _0809B85C @ =0x00001564
	adds r0, r7, r1
	str r4, [sp]
	str r4, [sp, #4]
	mov r2, r8
	str r2, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0x9d
	movs r3, #0xb1
	bl MainSprite_Add
	ldr r2, _0809B860 @ =0x000014A4
	adds r0, r7, r2
	str r4, [sp]
	str r4, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0x3c
	movs r3, #0xb1
	bl MainSprite_Add
	ldr r0, _0809B864 @ =0x00001E64
	adds r5, r7, r0
	str r4, [sp]
	str r4, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0x40
	movs r3, #0xb1
	bl MainSprite_Add
	str r4, [sp]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #1
	movs r3, #1
	bl MainSprite_SetAnim
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0x40
	movs r3, #1
	bl MainSprite_SetPose
	ldr r0, _0809B868 @ =0x00001444
	adds r5, r7, r0
	str r4, [sp]
	str r4, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0x39
	movs r3, #0xb1
	bl MainSprite_Add
	str r4, [sp]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0
	movs r3, #1
	bl MainSprite_SetAnim
	ldr r1, _0809B86C @ =0x00002584
	adds r0, r7, r1
	str r4, [sp]
	str r4, [sp, #4]
	mov r2, r8
	str r2, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0x93
	movs r3, #0xb1
	bl MainSprite_Add
	ldr r2, _0809B870 @ =0x000025E4
	adds r0, r7, r2
	str r4, [sp]
	str r4, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0x93
	movs r3, #0xb1
	bl MainSprite_Add
	movs r6, #0
	movs r0, #0xa0
	adds r0, r0, r7
	mov sl, r0
	ldr r1, _0809B874 @ =0x000015C4
	adds r4, r7, r1
	movs r5, #0xf
_0809B5AE:
	str r6, [sp]
	str r6, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r7, #0
	adds r1, #0xa0
	movs r2, #0x68
	movs r3, #0xb1
	bl MainSprite_Add
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809B5AE
	adds r0, r7, #0
	adds r0, #0x60
	str r0, [sp, #0x18]
	adds r1, r7, #0
	adds r1, #0xe0
	str r1, [sp, #0x24]
	adds r2, r7, #0
	adds r2, #0x80
	str r2, [sp, #0x1c]
	adds r0, #0x60
	str r0, [sp, #0x20]
	movs r1, #0
	mov r8, r1
	add r2, sp, #0x10
	mov sb, r2
	ldr r0, _0809B878 @ =0x00001EC4
	adds r6, r7, r0
	ldr r1, _0809B87C @ =0x00001CE4
	adds r4, r7, r1
	movs r5, #3
_0809B5F8:
	mov r2, r8
	str r2, [sp]
	str r2, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	mov r1, sb
	str r1, [sp, #0xc]
	adds r0, r4, #0
	mov r1, sl
	movs r2, #0x68
	movs r3, #0xb1
	bl MainSprite_Add
	mov r2, r8
	str r2, [sp]
	str r2, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	mov r1, sb
	str r1, [sp, #0xc]
	adds r0, r6, #0
	ldr r1, [sp, #0x18]
	movs r2, #0x41
	movs r3, #0xb1
	bl MainSprite_Add
	adds r6, #0x60
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809B5F8
	movs r4, #0
	movs r1, #0x75
	add r0, sp, #0x10
	strh r1, [r0]
	adds r6, r0, #0
	movs r0, #0x46
	strh r0, [r6, #2]
	ldr r2, _0809B880 @ =0x00001BC4
	adds r0, r7, r2
	str r4, [sp]
	str r4, [sp, #4]
	movs r5, #0x3c
	str r5, [sp, #8]
	str r6, [sp, #0xc]
	mov r1, sl
	movs r2, #0xca
	movs r3, #0xb1
	bl MainSprite_Add
	add r0, sp, #0x10
	strh r4, [r0]
	strh r4, [r6, #2]
	ldr r1, _0809B884 @ =0x00001C24
	adds r0, r7, r1
	str r4, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	ldr r1, [sp, #0x18]
	movs r2, #0x9c
	movs r3, #0xb1
	bl MainSprite_Add
	movs r1, #0x78
	add r0, sp, #0x10
	strh r1, [r0]
	movs r0, #0x68
	strh r0, [r6, #2]
	ldr r1, _0809B888 @ =0x00001C84
	adds r0, r7, r1
	str r4, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	mov r1, sl
	movs r2, #0xcb
	movs r3, #0xb1
	bl MainSprite_Add
	add r0, sp, #0x10
	strh r4, [r0]
	movs r0, #0x80
	strh r0, [r6, #2]
	ldr r1, _0809B88C @ =0x00002044
	adds r0, r7, r1
	str r4, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	mov r1, sl
	movs r2, #0xcf
	movs r3, #0xb1
	bl MainSprite_Add
	movs r6, #0
	ldr r0, _0809B890 @ =0x000020A4
	adds r4, r7, r0
	movs r5, #1
_0809B6C4:
	str r6, [sp]
	str r6, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	adds r0, r4, #0
	mov r1, sl
	movs r2, #0x68
	movs r3, #0xb1
	bl MainSprite_Add
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809B6C4
	movs r4, #0
	movs r0, #0x24
	mov sl, r0
	add r0, sp, #0x10
	mov r1, sl
	strh r1, [r0]
	add r2, sp, #0x10
	mov r8, r2
	movs r0, #0x70
	mov sb, r0
	mov r1, sb
	strh r1, [r2, #2]
	ldr r2, _0809B894 @ =0x000024C4
	adds r5, r7, r2
	adds r0, #0x90
	adds r6, r7, r0
	str r4, [sp]
	str r4, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0
	movs r3, #0x90
	bl MainSprite_Add
	str r4, [sp]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #4
	movs r3, #1
	bl MainSprite_SetAnim
	ldr r0, _0809B898 @ =0x00000B8C
	adds r5, r7, r0
	ldr r1, _0809B89C @ =0x0000DA6D
	adds r0, r5, #0
	bl Video_GetAuxSprite
	movs r1, #0xb6
	lsls r1, r1, #4
	adds r0, r7, r1
	adds r1, r5, #0
	movs r2, #0x91
	bl AuxSprite_Add
	ldr r2, _0809B8A0 @ =0x00000B67
	adds r0, r7, r2
	movs r1, #0
	strb r1, [r0]
	adds r2, #0x15
	adds r0, r7, r2
	mov r1, sl
	strh r1, [r0]
	adds r2, #2
	adds r0, r7, r2
	mov r1, sb
	strh r1, [r0]
	adds r2, #2
	adds r0, r7, r2
	strh r4, [r0]
	movs r1, #0x34
	add r0, sp, #0x10
	strh r1, [r0]
	movs r0, #0x64
	mov r1, r8
	strh r0, [r1, #2]
	ldr r2, _0809B8A4 @ =0x00002524
	adds r5, r7, r2
	adds r0, #0xbc
	adds r6, r7, r0
	str r4, [sp]
	str r4, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0
	movs r3, #0x94
	bl MainSprite_Add
	str r4, [sp]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0xd
	movs r3, #1
	bl MainSprite_SetAnim
	add r0, sp, #0x10
	strh r4, [r0]
	mov r0, r8
	strh r4, [r0, #2]
	movs r6, #0
	ldr r1, _0809B8A8 @ =0x00002164
	adds r4, r7, r1
	movs r5, #8
_0809B7AC:
	str r6, [sp]
	str r6, [sp, #4]
	movs r2, #0x3c
	mov r8, r2
	str r2, [sp, #8]
	add r0, sp, #0x10
	str r0, [sp, #0xc]
	adds r0, r4, #0
	ldr r1, [sp, #0x18]
	movs r2, #0xa
	movs r3, #0xb1
	bl MainSprite_Add
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809B7AC
	movs r4, #0
	add r0, sp, #0x10
	strh r4, [r0]
	adds r5, r0, #0
	strh r4, [r5, #2]
	ldr r1, _0809B8AC @ =0x00001504
	adds r0, r7, r1
	str r4, [sp]
	str r4, [sp, #4]
	mov r2, r8
	str r2, [sp, #8]
	str r5, [sp, #0xc]
	ldr r1, [sp, #0x18]
	movs r2, #0x94
	movs r3, #0x91
	bl MainSprite_Add
	movs r1, #8
	add r0, sp, #0x10
	strh r1, [r0]
	movs r0, #0x14
	strh r0, [r5, #2]
	ldr r1, _0809B8B0 @ =0x00002644
	adds r0, r7, r1
	str r4, [sp]
	str r4, [sp, #4]
	mov r2, r8
	str r2, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	ldr r1, [sp, #0x24]
	movs r2, #0
	movs r3, #0x91
	bl MainSprite_Add
	add r0, sp, #0x10
	strh r4, [r0]
	strh r4, [r5, #2]
	adds r6, r0, #0
	ldr r2, _0809B8B4 @ =0x000026A4
	adds r4, r7, r2
	movs r0, #0
	mov r8, r0
	movs r5, #3
_0809B826:
	mov r1, r8
	str r1, [sp]
	str r1, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r4, #0
	ldr r1, [sp, #0x18]
	movs r2, #0xaa
	movs r3, #0x91
	bl MainSprite_Add
	ldrh r0, [r6, #2]
	adds r0, #0xd
	strh r0, [r6, #2]
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	b _0809B8B8
	.align 2, 0
_0809B84C: .4byte 0xFFFF0000
_0809B850: .4byte 0x00000F64
_0809B854: .4byte 0x00000FC4
_0809B858: .4byte 0x00001024
_0809B85C: .4byte 0x00001564
_0809B860: .4byte 0x000014A4
_0809B864: .4byte 0x00001E64
_0809B868: .4byte 0x00001444
_0809B86C: .4byte 0x00002584
_0809B870: .4byte 0x000025E4
_0809B874: .4byte 0x000015C4
_0809B878: .4byte 0x00001EC4
_0809B87C: .4byte 0x00001CE4
_0809B880: .4byte 0x00001BC4
_0809B884: .4byte 0x00001C24
_0809B888: .4byte 0x00001C84
_0809B88C: .4byte 0x00002044
_0809B890: .4byte 0x000020A4
_0809B894: .4byte 0x000024C4
_0809B898: .4byte 0x00000B8C
_0809B89C: .4byte 0x0000DA6D
_0809B8A0: .4byte 0x00000B67
_0809B8A4: .4byte 0x00002524
_0809B8A8: .4byte 0x00002164
_0809B8AC: .4byte 0x00001504
_0809B8B0: .4byte 0x00002644
_0809B8B4: .4byte 0x000026A4
_0809B8B8:
	bge _0809B826
	movs r0, #0
	add r1, sp, #0x10
	strh r0, [r1]
	strh r0, [r1, #2]
	movs r6, #0
	ldr r2, _0809BC94 @ =0x00001084
	adds r4, r7, r2
	movs r5, #9
_0809B8CA:
	str r6, [sp]
	str r6, [sp, #4]
	movs r0, #0x3c
	mov r8, r0
	str r0, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r0, r4, #0
	ldr r1, [sp, #0x18]
	movs r2, #0x64
	movs r3, #0xb1
	bl MainSprite_Add
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809B8CA
	movs r4, #0
	add r0, sp, #0x10
	strh r4, [r0]
	adds r5, r0, #0
	strh r4, [r5, #2]
	ldr r2, _0809BC98 @ =0x00002824
	adds r0, r7, r2
	str r4, [sp]
	str r4, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	str r5, [sp, #0xc]
	ldr r1, [sp, #0x18]
	movs r2, #0x4d
	movs r3, #0x91
	bl MainSprite_Add
	ldr r2, _0809BC9C @ =0x00002884
	adds r0, r7, r2
	str r4, [sp]
	str r4, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	ldr r1, [sp, #0x18]
	movs r2, #0x4e
	movs r3, #0x91
	bl MainSprite_Add
	add r0, sp, #0x10
	strh r4, [r0]
	strh r4, [r5, #2]
	ldr r0, [sp, #0x18]
	mov sb, r0
	movs r1, #0x3c
	mov sl, r1
	ldr r2, _0809BCA0 @ =0x00002A64
	adds r2, r2, r7
	mov r8, r2
	ldr r0, _0809BCA4 @ =0x000028E4
	adds r6, r7, r0
	add r4, sp, #0x10
	movs r5, #3
_0809B944:
	movs r1, #1
	str r1, [sp]
	movs r2, #0
	str r2, [sp, #4]
	mov r0, sl
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	adds r0, r6, #0
	mov r1, sb
	movs r2, #0x47
	movs r3, #0x91
	bl MainSprite_Add
	movs r1, #1
	str r1, [sp]
	movs r2, #0
	str r2, [sp, #4]
	mov r0, sl
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	mov r0, r8
	mov r1, sb
	movs r2, #0x46
	movs r3, #0x91
	bl MainSprite_Add
	ldrh r0, [r4, #2]
	adds r0, #8
	strh r0, [r4, #2]
	movs r1, #0x60
	add r8, r1
	adds r6, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809B944
	movs r0, #0
	add r1, sp, #0x10
	strh r0, [r1]
	strh r0, [r1, #2]
	movs r5, #0
	ldr r6, [sp, #0x1c]
	mov sb, r5
_0809B998:
	lsls r2, r5, #1
	adds r4, r2, r5
	lsls r4, r4, #5
	ldr r0, _0809BCA8 @ =0x00002CA4
	adds r4, r4, r0
	adds r4, r7, r4
	adds r2, #9
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r1, #1
	mov sl, r1
	str r1, [sp]
	mov r0, sb
	str r0, [sp, #4]
	movs r1, #0x3c
	mov r8, r1
	str r1, [sp, #8]
	add r0, sp, #0x10
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r6, #0
	movs r3, #0x91
	bl MainSprite_Add
	adds r5, #1
	lsls r2, r5, #0x10
	lsrs r2, r2, #0x10
	mov r1, sb
	str r1, [sp]
	adds r0, r4, #0
	adds r1, r6, #0
	movs r3, #1
	bl MainSprite_SetAnim
	cmp r5, #3
	ble _0809B998
	ldr r2, _0809BCAC @ =0x00002BE4
	adds r0, r7, r2
	mov r1, sl
	str r1, [sp]
	movs r4, #0
	str r4, [sp, #4]
	mov r2, r8
	str r2, [sp, #8]
	add r5, sp, #0x10
	str r5, [sp, #0xc]
	ldr r1, [sp, #0x1c]
	movs r2, #0
	movs r3, #0x91
	bl MainSprite_Add
	ldr r1, _0809BCB0 @ =0x00002C44
	adds r0, r7, r1
	mov r2, sl
	str r2, [sp]
	str r4, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	ldr r1, [sp, #0x1c]
	movs r2, #3
	movs r3, #0x91
	bl MainSprite_Add
	add r0, sp, #0x10
	strh r4, [r0]
	strh r4, [r5, #2]
	movs r5, #0
	movs r6, #0x90
	lsls r6, r6, #0xd
	ldr r0, _0809BCB4 @ =0x00002FA4
	adds r4, r7, r0
_0809BA2A:
	lsrs r2, r6, #0x10
	movs r0, #1
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r0, r4, #0
	ldr r1, [sp, #0x1c]
	movs r3, #0x91
	bl MainSprite_Add
	movs r2, #0x80
	lsls r2, r2, #9
	adds r6, r6, r2
	adds r4, #0x60
	adds r5, #1
	cmp r5, #5
	ble _0809BA2A
	ldr r0, _0809BCB8 @ =0x000031E4
	adds r4, r7, r0
	movs r5, #7
_0809BA5A:
	movs r0, #1
	str r0, [sp]
	movs r6, #0
	str r6, [sp, #4]
	movs r1, #0x3c
	mov r8, r1
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	adds r0, r4, #0
	ldr r1, [sp, #0x1c]
	movs r2, #0x11
	movs r3, #0x91
	bl MainSprite_Add
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809BA5A
	add r0, sp, #0x10
	strh r6, [r0]
	adds r4, r0, #0
	strh r6, [r4, #2]
	ldr r1, _0809BCBC @ =0x00002E24
	adds r0, r7, r1
	str r6, [sp]
	str r6, [sp, #4]
	mov r2, r8
	str r2, [sp, #8]
	str r4, [sp, #0xc]
	ldr r1, [sp, #0x18]
	movs r2, #0x36
	movs r3, #0xb0
	bl MainSprite_Add
	ldr r1, _0809BCC0 @ =0x00002E84
	adds r0, r7, r1
	str r6, [sp]
	str r6, [sp, #4]
	mov r2, r8
	str r2, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	ldr r1, [sp, #0x18]
	movs r2, #0x37
	movs r3, #0xb0
	bl MainSprite_Add
	ldr r2, _0809BCC4 @ =0x00002EE4
	adds r0, r7, r2
	str r6, [sp]
	str r6, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	ldr r1, [sp, #0x18]
	movs r2, #0x34
	movs r3, #0xb0
	bl MainSprite_Add
	ldr r1, _0809BCC8 @ =0x00002F44
	adds r0, r7, r1
	str r6, [sp]
	str r6, [sp, #4]
	mov r2, r8
	str r2, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	ldr r1, [sp, #0x18]
	movs r2, #0x35
	movs r3, #0xb0
	bl MainSprite_Add
	add r0, sp, #0x10
	strh r6, [r0]
	strh r6, [r4, #2]
	ldr r2, _0809BCCC @ =0x000034E4
	adds r0, r7, r2
	str r6, [sp]
	str r6, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	ldr r1, [sp, #0x20]
	movs r2, #4
	movs r3, #0xb0
	bl MainSprite_Add
	ldr r1, _0809BCD0 @ =0x00003544
	adds r0, r7, r1
	str r6, [sp]
	str r6, [sp, #4]
	mov r2, r8
	str r2, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	ldr r1, [sp, #0x20]
	movs r2, #0x19
	movs r3, #0xb0
	bl MainSprite_Add
	ldr r2, _0809BCD4 @ =0x000035A4
	adds r0, r7, r2
	str r6, [sp]
	str r6, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	ldr r1, [sp, #0x20]
	movs r2, #0x1b
	movs r3, #0xb0
	bl MainSprite_Add
	add r0, sp, #0x10
	strh r6, [r0]
	strh r6, [r4, #2]
	adds r6, r0, #0
	ldr r0, _0809BCD8 @ =0x00003664
	adds r4, r7, r0
	movs r1, #0
	mov r8, r1
	movs r5, #2
_0809BB54:
	mov r2, r8
	str r2, [sp]
	str r2, [sp, #4]
	movs r0, #0x3c
	mov sb, r0
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r4, #0
	ldr r1, [sp, #0x20]
	movs r2, #8
	movs r3, #0xb0
	bl MainSprite_Add
	ldrh r0, [r6]
	adds r0, #8
	strh r0, [r6]
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809BB54
	movs r2, #0
	movs r1, #0x10
	add r0, sp, #0x10
	strh r1, [r0]
	adds r4, r0, #0
	ldr r0, _0809BCDC @ =0x0000FFFC
	strh r0, [r4, #2]
	ldr r1, _0809BCE0 @ =0x00003604
	adds r0, r7, r1
	str r2, [sp]
	str r2, [sp, #4]
	mov r2, sb
	str r2, [sp, #8]
	str r4, [sp, #0xc]
	ldr r1, [sp, #0x20]
	movs r2, #0x12
	movs r3, #0xb0
	bl MainSprite_Add
	ldr r1, _0809BCE4 @ =0x0000FFC8
	add r0, sp, #0x10
	strh r1, [r0]
	movs r0, #0x38
	strh r0, [r4, #2]
	add r6, sp, #0x10
	ldr r0, _0809BCE8 @ =0x00003784
	adds r4, r7, r0
	movs r1, #0
	mov r8, r1
	movs r5, #3
_0809BBB8:
	mov r2, r8
	str r2, [sp]
	str r2, [sp, #4]
	movs r0, #0x3c
	mov sb, r0
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r4, #0
	ldr r1, [sp, #0x20]
	movs r2, #8
	movs r3, #0xb0
	bl MainSprite_Add
	ldrh r0, [r6]
	adds r0, #8
	strh r0, [r6]
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809BBB8
	movs r2, #0
	movs r1, #0x58
	add r0, sp, #0x10
	strh r1, [r0]
	adds r4, r0, #0
	movs r0, #0x38
	strh r0, [r4, #2]
	ldr r1, _0809BCEC @ =0x00003904
	adds r0, r7, r1
	str r2, [sp]
	str r2, [sp, #4]
	mov r2, sb
	str r2, [sp, #8]
	str r4, [sp, #0xc]
	ldr r1, [sp, #0x20]
	movs r2, #8
	movs r3, #0xb0
	bl MainSprite_Add
	ldr r1, _0809BCF0 @ =0x0000FFD0
	add r0, sp, #0x10
	strh r1, [r0]
	movs r0, #0x48
	strh r0, [r4, #2]
	add r6, sp, #0x10
	ldr r0, _0809BCF4 @ =0x00003964
	adds r4, r7, r0
	movs r1, #0
	mov r8, r1
	movs r5, #3
_0809BC1C:
	mov r2, r8
	str r2, [sp]
	str r2, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r4, #0
	ldr r1, [sp, #0x20]
	movs r2, #8
	movs r3, #0xb0
	bl MainSprite_Add
	ldrh r0, [r6]
	adds r0, #8
	strh r0, [r6]
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809BC1C
	movs r5, #0
	ldr r0, _0809BCF8 @ =0x00000BE4
	adds r4, r7, r0
	ldr r1, _0809BCFC @ =0x0000A47C
	adds r0, r4, #0
	bl Video_GetAuxSprite
	ldr r1, _0809BD00 @ =0x00000BB8
	adds r0, r7, r1
	adds r1, r4, #0
	movs r2, #0x91
	bl AuxSprite_Add
	ldr r1, _0809BD04 @ =0x00000143
	adds r0, r4, #0
	bl Video_SetAuxSpritePltt
	ldr r2, _0809BD08 @ =0x00000BBF
	adds r0, r7, r2
	strb r5, [r0]
	ldr r0, _0809BD0C @ =0x00000BD4
	adds r1, r7, r0
	movs r0, #0xa0
	strh r0, [r1]
	adds r2, #0x17
	adds r1, r7, r2
	movs r0, #0x58
	strh r0, [r1]
	ldr r1, _0809BD10 @ =0x00000BD8
	adds r0, r7, r1
	strh r5, [r0]
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0809BC90: .4byte 0x0000E040
_0809BC94: .4byte 0x00001084
_0809BC98: .4byte 0x00002824
_0809BC9C: .4byte 0x00002884
_0809BCA0: .4byte 0x00002A64
_0809BCA4: .4byte 0x000028E4
_0809BCA8: .4byte 0x00002CA4
_0809BCAC: .4byte 0x00002BE4
_0809BCB0: .4byte 0x00002C44
_0809BCB4: .4byte 0x00002FA4
_0809BCB8: .4byte 0x000031E4
_0809BCBC: .4byte 0x00002E24
_0809BCC0: .4byte 0x00002E84
_0809BCC4: .4byte 0x00002EE4
_0809BCC8: .4byte 0x00002F44
_0809BCCC: .4byte 0x000034E4
_0809BCD0: .4byte 0x00003544
_0809BCD4: .4byte 0x000035A4
_0809BCD8: .4byte 0x00003664
_0809BCDC: .4byte 0x0000FFFC
_0809BCE0: .4byte 0x00003604
_0809BCE4: .4byte 0x0000FFC8
_0809BCE8: .4byte 0x00003784
_0809BCEC: .4byte 0x00003904
_0809BCF0: .4byte 0x0000FFD0
_0809BCF4: .4byte 0x00003964
_0809BCF8: .4byte 0x00000BE4
_0809BCFC: .4byte 0x0000A47C
_0809BD00: .4byte 0x00000BB8
_0809BD04: .4byte 0x00000143
_0809BD08: .4byte 0x00000BBF
_0809BD0C: .4byte 0x00000BD4
_0809BD10: .4byte 0x00000BD8
