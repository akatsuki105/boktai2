	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r4, _08238680 @ =0x04000208
	movs r0, #0
	mov r8, r0
	strh r0, [r4]
	ldr r3, _08238684 @ =0x04000200
	ldrh r1, [r3]
	ldr r0, _08238688 @ =0x0000FF7F
	ands r0, r1
	strh r0, [r3]
	ldr r1, _0823868C @ =0x03002CB0
	ldr r0, _08238690 @ =FUN_082386e4
	str r0, [r1, #4]
	movs r6, #1
	strh r6, [r4]
	ldr r0, _08238694 @ =0x04000202
	movs r5, #0x80
	strh r5, [r0]
	ldr r2, _08238698 @ =0x04000128
	ldrh r0, [r2]
	movs r7, #0x80
	lsls r7, r7, #7
	adds r1, r7, #0
	orrs r0, r1
	strh r0, [r2]
	mov r0, r8
	strh r0, [r4]
	ldrh r0, [r3]
	orrs r0, r5
	strh r0, [r3]
	strh r6, [r4]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08238680: .4byte 0x04000208
_08238684: .4byte 0x04000200
_08238688: .4byte 0x0000FF7F
_0823868C: .4byte 0x03002CB0
_08238690: .4byte FUN_082386e4
_08238694: .4byte 0x04000202
_08238698: .4byte 0x04000128
