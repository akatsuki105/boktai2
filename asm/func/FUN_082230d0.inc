	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r1, _08223134 @ =0x00000F08
	adds r0, r6, r1
	movs r1, #0x32
	strh r1, [r0]
	ldr r2, _08223138 @ =0x00000F0A
	adds r0, r6, r2
	strh r1, [r0]
	ldr r0, _0822313C @ =0x00000DC8
	adds r5, r6, r0
	adds r1, #0xe5
	adds r0, r5, #0
	bl FUN_0822b20c
	ldr r2, _08223140 @ =0x00000F04
	adds r1, r6, r2
	ldr r0, _08223144 @ =0x00000DD4
	adds r4, r6, r0
	ldr r0, [r4]
	str r0, [r1]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r5, #0
	bl FUN_0822b20c
	ldr r4, [r4]
	ldr r2, _08223148 @ =0x00000EE4
	adds r1, r6, r2
	movs r2, #0xf
_0822310C:
	ldrh r0, [r4]
	strh r0, [r1]
	adds r4, #2
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _0822310C
	ldr r0, _08223144 @ =0x00000DD4
	adds r1, r6, r0
	ldr r2, _08223148 @ =0x00000EE4
	adds r0, r6, r2
	str r0, [r1]
	ldr r0, _0822314C @ =0x00000F48
	adds r1, r6, r0
	ldr r0, _08223150 @ =FUN_08223154
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08223134: .4byte 0x00000F08
_08223138: .4byte 0x00000F0A
_0822313C: .4byte 0x00000DC8
_08223140: .4byte 0x00000F04
_08223144: .4byte 0x00000DD4
_08223148: .4byte 0x00000EE4
_0822314C: .4byte 0x00000F48
_08223150: .4byte FUN_08223154
