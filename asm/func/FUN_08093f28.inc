	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _08093F58 @ =0x00003F9C
	adds r0, r4, r1
	ldrb r0, [r0]
	ldr r2, _08093F5C @ =0x00003AEE
	adds r1, r4, r2
	ldrb r1, [r1]
	bl GetItemID
	adds r5, r0, #0
	ldr r1, _08093F60 @ =0x08DAA8D8
	lsls r0, r5, #4
	adds r0, r0, r1
	ldrh r0, [r0, #2]
	subs r0, #1
	cmp r0, #0xe
	bls _08093F4E
	b _08094064
_08093F4E:
	lsls r0, r0, #2
	ldr r1, _08093F64 @ =_08093F68
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08093F58: .4byte 0x00003F9C
_08093F5C: .4byte 0x00003AEE
_08093F60: .4byte 0x08DAA8D8
_08093F64: .4byte _08093F68
_08093F68: @ jump table
	.4byte _08093FA4 @ case 0
	.4byte _08093FA4 @ case 1
	.4byte _08093FA4 @ case 2
	.4byte _08093FAC @ case 3
	.4byte _08093FA4 @ case 4
	.4byte _08094020 @ case 5
	.4byte _08093FC0 @ case 6
	.4byte _08093FE0 @ case 7
	.4byte _08093FA4 @ case 8
	.4byte _08094002 @ case 9
	.4byte _08094018 @ case 10
	.4byte _08094020 @ case 11
	.4byte _08094044 @ case 12
	.4byte _08094058 @ case 13
	.4byte _08094064 @ case 14
_08093FA4:
	adds r0, r4, #0
	bl FUN_080927c4
	b _08094064
_08093FAC:
	ldr r0, _08093FBC @ =0x0000038A
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_08092a94
	b _08094064
	.align 2, 0
_08093FBC: .4byte 0x0000038A
_08093FC0:
	ldr r0, _08093FD8 @ =0x0000010D
	bl PlaySound_082406e0
	cmp r5, #0x1e
	bne _08093FD2
	movs r0, #0xc1
	lsls r0, r0, #1
	bl PlaySound_082406e0
_08093FD2:
	ldr r2, _08093FDC @ =0x00003AEE
	adds r0, r4, r2
	b _0809402A
	.align 2, 0
_08093FD8: .4byte 0x0000010D
_08093FDC: .4byte 0x00003AEE
_08093FE0:
	ldr r0, _08093FF4 @ =0x08DAA8D8
	lsls r1, r5, #4
	adds r1, r1, r0
	ldrh r0, [r1, #6]
	cmp r0, #2
	bne _08093FF8
	adds r0, r4, #0
	bl FUN_08092cac
	b _08094064
	.align 2, 0
_08093FF4: .4byte 0x08DAA8D8
_08093FF8:
	ldrh r1, [r1, #6]
	adds r0, r4, #0
	bl FUN_08092c7c
	b _08094064
_08094002:
	ldr r0, _08094014 @ =0x08DAA8D8
	lsls r1, r5, #4
	adds r1, r1, r0
	ldrh r1, [r1, #6]
	adds r0, r4, #0
	bl FUN_080933b4
	b _08094064
	.align 2, 0
_08094014: .4byte 0x08DAA8D8
_08094018:
	adds r0, r4, #0
	bl FUN_080937d4
	b _08094064
_08094020:
	ldr r0, _0809403C @ =0x0000010D
	bl PlaySound_082406e0
	ldr r1, _08094040 @ =0x00003AEE
	adds r0, r4, r1
_0809402A:
	ldrb r1, [r0]
	adds r0, r4, #0
	bl FUN_08091e64
	adds r0, r4, #0
	bl FUN_08092744
	b _08094064
	.align 2, 0
_0809403C: .4byte 0x0000010D
_08094040: .4byte 0x00003AEE
_08094044:
	ldr r0, _08094054 @ =0x0000038A
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_08093bb4
	b _08094064
	.align 2, 0
_08094054: .4byte 0x0000038A
_08094058:
	ldr r0, _0809406C @ =0x0000038A
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_08093d38
_08094064:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809406C: .4byte 0x0000038A
