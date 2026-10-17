	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	str r0, [sp, #8]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r7, _081F4A68 @ =0x030046B8
	ldr r0, _081F4A6C @ =0x000003FF
	mov sb, r0
	mov r5, sp
	adds r6, r1, #0
	adds r6, #0xd6
	ldr r1, _081F4A70 @ =0x0203B400
	mov sl, r1
	movs r0, #5
	mov r8, r0
_081F4A2E:
	lsls r0, r6, #0x18
	lsrs r4, r0, #0x18
	ldr r0, [r7]
	adds r0, #1
	mov r1, sb
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r1, _081F4A70 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	adds r3, r0, #4
	ldr r2, _081F4A74 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _081F4A78
	asrs r1, r0, #0xc
	b _081F4A7E
	.align 2, 0
_081F4A68: .4byte 0x030046B8
_081F4A6C: .4byte 0x000003FF
_081F4A70: .4byte 0x0203B400
_081F4A74: .4byte gSineTable
_081F4A78:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081F4A7E:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	lsls r0, r4, #1
	ldr r1, _081F4A98 @ =gSineTable
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _081F4A9C
	asrs r0, r0, #0xc
	b _081F4AA2
	.align 2, 0
_081F4A98: .4byte gSineTable
_081F4A9C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081F4AA2:
	strh r0, [r5, #4]
	ldr r1, [r7]
	adds r1, #1
	mov r0, sb
	ands r1, r0
	lsls r0, r1, #1
	add r0, sl
	ldrh r0, [r0]
	movs r2, #0xf
	ands r0, r2
	strh r0, [r5, #2]
	adds r1, #1
	mov r0, sb
	ands r1, r0
	str r1, [r7]
	lsls r1, r1, #1
	add r1, sl
	ldrh r2, [r1]
	movs r0, #0xf
	ands r2, r0
	adds r2, #0x1e
	ldr r0, [sp, #8]
	mov r1, sp
	movs r3, #5
	bl FUN_081ee07c
	adds r6, #0xe
	movs r1, #1
	rsbs r1, r1, #0
	add r8, r1
	mov r0, r8
	cmp r0, #0
	bge _081F4A2E
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
