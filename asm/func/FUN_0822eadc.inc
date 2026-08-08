	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r7, r1, #0
	adds r4, r2, #0
	adds r5, r3, #0
	movs r0, #0
	bl GetTilemapBuffer
	mov r8, r0
	mov ip, r6
	adds r2, r6, r4
	adds r4, r7, r5
	cmp r7, r4
	bhs _0822EB20
	lsls r5, r6, #1
_0822EAFE:
	mov r6, ip
	adds r1, r7, #1
	cmp r6, r2
	bhs _0822EB1A
	ldr r0, _0822EB2C @ =0x0000F001
	adds r3, r0, #0
	lsls r0, r7, #6
	add r0, r8
	adds r0, r5, r0
_0822EB10:
	strh r3, [r0]
	adds r0, #2
	adds r6, #1
	cmp r6, r2
	blo _0822EB10
_0822EB1A:
	adds r7, r1, #0
	cmp r7, r4
	blo _0822EAFE
_0822EB20:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0822EB2C: .4byte 0x0000F001
