	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldr r1, _0809A7A4 @ =0x000009FC
	adds r0, r7, r1
	movs r2, #0
	mov r8, r2
	movs r1, #1
	strh r1, [r0]
	ldr r0, _0809A7A8 @ =0x03003530
	str r1, [r0]
	ldr r5, _0809A7AC @ =0x03003E78
	ldrh r0, [r5]
	ldr r3, _0809A7B0 @ =0x00003B14
	adds r1, r7, r3
	strh r0, [r1]
	movs r4, #0x80
	lsls r4, r4, #1
	bics r0, r4
	ldr r1, _0809A7B4 @ =0xFFFFFDFF
	ands r0, r1
	ldr r1, _0809A7B8 @ =0xFFFFFBFF
	ands r0, r1
	ldr r1, _0809A7BC @ =0xFFFFF7FF
	ands r0, r1
	strh r0, [r5]
	movs r0, #1
	bl GetTilemapBuffer
	movs r6, #0xd8
	lsls r6, r6, #1
	adds r1, r7, r6
	ldr r2, _0809A7C0 @ =0x04000200
	bl CpuSet
	ldr r1, _0809A7C4 @ =0x03003ED0
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
	adds r1, #0x30
	ldm r1!, {r2, r3, r6}
	stm r0!, {r2, r3, r6}
	ldm r1!, {r2, r3, r6}
	stm r0!, {r2, r3, r6}
	ldm r1!, {r2, r3, r6}
	stm r0!, {r2, r3, r6}
	ldm r1!, {r2, r3, r6}
	stm r0!, {r2, r3, r6}
	ldr r2, _0809A7C8 @ =0x04000050
	ldrh r1, [r2]
	movs r3, #0x9b
	lsls r3, r3, #4
	adds r0, r7, r3
	strh r1, [r0]
	ldr r0, _0809A7CC @ =0x0400000A
	ldrh r1, [r0]
	ldr r6, _0809A7D0 @ =0x000009B4
	adds r0, r7, r6
	strh r1, [r0]
	mov r0, r8
	strh r0, [r2]
	ldr r1, _0809A7D4 @ =0x03004460
	movs r0, #0x40
	str r0, [r1]
	movs r0, #1
	movs r1, #2
	bl SetBGCharBaseDirect
	movs r0, #1
	movs r1, #1
	bl SetBGPrioDirect
	ldr r0, _0809A7D8 @ =0x0300449C
	ldrh r1, [r0]
	ldr r2, _0809A7DC @ =0x00003B16
	adds r0, r7, r2
	strh r1, [r0]
	ldr r0, _0809A7E0 @ =0x030044B4
	ldrh r1, [r0]
	ldr r3, _0809A7E4 @ =0x00003B18
	adds r0, r7, r3
	strh r1, [r0]
	ldr r0, _0809A7E8 @ =0x030044B0
	ldrb r1, [r0]
	ldr r6, _0809A7EC @ =0x00003B1A
	adds r0, r7, r6
	strb r1, [r0]
	ldr r0, _0809A7F0 @ =0x03004498
	ldrb r1, [r0]
	adds r2, #5
	adds r0, r7, r2
	strb r1, [r0]
	bl Video_ClearMosaic
	ldrh r0, [r5]
	orrs r4, r0
	strh r4, [r5]
	movs r3, #1
	ldr r6, _0809A7F4 @ =0x0000108C
	adds r1, r7, r6
	movs r2, #9
_0809A774:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0809A774
	movs r1, #0
	ldr r2, _0809A7F8 @ =0x00003AE4
	adds r0, r7, r2
	strb r1, [r0]
	adds r0, r7, #0
	bl FUN_0809a67c
	ldr r3, _0809A7FC @ =0x00004003
	adds r1, r7, r3
	movs r0, #0xff
	strb r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809A7A4: .4byte 0x000009FC
_0809A7A8: .4byte 0x03003530
_0809A7AC: .4byte 0x03003E78
_0809A7B0: .4byte 0x00003B14
_0809A7B4: .4byte 0xFFFFFDFF
_0809A7B8: .4byte 0xFFFFFBFF
_0809A7BC: .4byte 0xFFFFF7FF
_0809A7C0: .4byte 0x04000200
_0809A7C4: .4byte 0x03003ED0
_0809A7C8: .4byte 0x04000050
_0809A7CC: .4byte 0x0400000A
_0809A7D0: .4byte 0x000009B4
_0809A7D4: .4byte 0x03004460
_0809A7D8: .4byte 0x0300449C
_0809A7DC: .4byte 0x00003B16
_0809A7E0: .4byte 0x030044B4
_0809A7E4: .4byte 0x00003B18
_0809A7E8: .4byte 0x030044B0
_0809A7EC: .4byte 0x00003B1A
_0809A7F0: .4byte 0x03004498
_0809A7F4: .4byte 0x0000108C
_0809A7F8: .4byte 0x00003AE4
_0809A7FC: .4byte 0x00004003
