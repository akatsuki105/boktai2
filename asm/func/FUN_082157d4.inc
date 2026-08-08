	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r6, r0, #0
	ldr r0, _08215864 @ =0x00000DBC
	adds r5, r6, r0
	add r1, sp, #0x14
	mov r8, r1
	movs r4, #0
	str r4, [sp, #0x10]
	add r0, sp, #0x10
	ldr r2, _08215868 @ =0x05000002
	bl CpuSet
	adds r7, r6, #0
	adds r7, #0x18
	str r4, [sp]
	str r4, [sp, #4]
	movs r0, #0x3c
	mov sl, r0
	str r0, [sp, #8]
	mov r1, r8
	str r1, [sp, #0xc]
	adds r0, r5, #0
	adds r1, r7, #0
	movs r2, #0x3f
	movs r3, #0x30
	bl FUN_0822f3fc
	ldr r0, [r5, #8]
	movs r1, #1
	mov sb, r1
	orrs r0, r1
	str r0, [r5, #8]
	ldr r1, _0821586C @ =0x00000E1C
	adds r0, r6, r1
	str r4, [sp]
	str r4, [sp, #4]
	mov r1, sl
	str r1, [sp, #8]
	mov r1, r8
	str r1, [sp, #0xc]
	adds r1, r7, #0
	movs r2, #0x43
	movs r3, #0x30
	bl FUN_0822f3fc
	ldr r0, [r5, #0x68]
	mov r1, sb
	orrs r0, r1
	str r0, [r5, #0x68]
	ldr r0, _08215870 @ =0x00000E7C
	adds r6, r6, r0
	ldr r0, _08215874 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _08215878 @ =0x0000093E
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r0, [r6]
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08215864: .4byte 0x00000DBC
_08215868: .4byte 0x05000002
_0821586C: .4byte 0x00000E1C
_08215870: .4byte 0x00000E7C
_08215874: .4byte 0x030046A0
_08215878: .4byte 0x0000093E
